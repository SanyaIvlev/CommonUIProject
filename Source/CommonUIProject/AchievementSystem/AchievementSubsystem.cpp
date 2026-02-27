#include "AchievementSubsystem.h"

#include "AchievementSubsystemSettings.h"
#include "UAchievementRecord.h"

void UAchievementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const UAchievementSubsystemSettings* AchievementSettings = GetDefault<UAchievementSubsystemSettings>();
	AchievementsRecords.SetNum(AchievementSettings->ExistingAchievements.Num());
	
	for(const TSoftObjectPtr<UAchievementInfo>& SoftAchievementReference : AchievementSettings->ExistingAchievements)
	{
		UAchievementInfo* LoadedAchievement = SoftAchievementReference.LoadSynchronous();
		
		if (LoadedAchievement != nullptr)
		{
			int32 Index = LoadedAchievement->ID;
			
			UAchievementRecord* Record = NewObject<UAchievementRecord>();
			Record->Initialize(LoadedAchievement->TargetValue);
			
			AchievementsRecords[Index] = Record;
		}
	}
	
	bEnableLogs = AchievementSettings->bEnableLogs;
	bEnableHiddenAchievements = AchievementSettings->bEnableHiddenAchievements;
	
	if (bEnableLogs)
	{
		UE_LOG(LogTemp, Warning, TEXT("Achievement Subsystem Initialized with achievements count: %d"), AchievementsRecords.Num());
	}
	
	
}

void UAchievementSubsystem::AddProgress(int32 ID, int32 Amount)
{
	if (ID < 0 || ID >= AchievementsRecords.Num())
	{
		return;
	}
	
	if (AchievementsRecords[ID] == nullptr)
	{
		return;
	}
	
	if (AchievementsRecords[ID]->bIsUnlocked)
	{
		return;
	}
	
	AchievementsRecords[ID]->AddProgress(Amount);
	
	TSoftObjectPtr<UAchievementInfo> AchievementInfo = GetAchievementInfo(ID);
	
	if (!AchievementInfo.IsValid())
	{
		if (bEnableLogs)
		{
			UE_LOG(LogTemp, Error, TEXT("Achievement info with ID %d not found"), ID);
		}
	}
	
	bool bIsUnlocked = IsUnlocked(ID);
	
	if (bEnableLogs)
	{
		UE_LOG(LogTemp, Log, TEXT("Is unlocked with ID %d - %d") , ID, bIsUnlocked);
	}
	
	if (IsUnlocked(ID))
	{
		OnAchievementUnlocked.Broadcast(AchievementInfo);	
	}
	else if (!(AchievementInfo->Type == EAchievementType::Hidden && bEnableHiddenAchievements))
	{
		int32 CurrentProgress = AchievementsRecords[ID]->GetCurrentProgress();
		OnAchievementProgressUpdated.Broadcast(AchievementInfo, CurrentProgress);
	}
}

UAchievementRecord* UAchievementSubsystem::GetAchievementRecord(int32 ID)
{
	if (ID < 0 || ID >= AchievementsRecords.Num())
	{
		return nullptr;
	}
	
	return AchievementsRecords[ID];
}

TSoftObjectPtr<UAchievementInfo> UAchievementSubsystem::GetAchievementInfo(int32 ID)
{
	const TArray<TSoftObjectPtr<UAchievementInfo>>& AllAchievementsInfo = GetAllAchievementInfos();
	
	for (const TSoftObjectPtr<UAchievementInfo>& SoftAchievementReference : AllAchievementsInfo)
	{
		if (SoftAchievementReference->ID == ID)
		{
			return SoftAchievementReference;
		}
	}
	
	return nullptr;
}

void UAchievementSubsystem::UnlockAchievement(int32 ID)
{
	UAchievementRecord* Record = AchievementsRecords[ID];
	
	Record->bIsUnlocked = true;
	AddProgress(ID, Record->GetTargetProgress());
}

bool UAchievementSubsystem::IsUnlocked(int32 ID)
{
	return AchievementsRecords[ID]->bIsUnlocked;
}

TArray<TSoftObjectPtr<UAchievementInfo>> UAchievementSubsystem::GetAllAchievementInfos()
{
	const UAchievementSubsystemSettings* AchievementSettings = GetDefault<UAchievementSubsystemSettings>();
	
	return AchievementSettings->ExistingAchievements;
}

