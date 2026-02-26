#pragma once

#include "CoreMinimal.h"
#include "AchievementInfo.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AchievementSubsystem.generated.h"


class UAchievementRecord;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievementProgressChange, TSoftObjectPtr<UAchievementInfo>, AchievementInfo, int32, CurrentProgress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementUnlock, TSoftObjectPtr<UAchievementInfo>, AchievementInfo);

UCLASS()
class COMMONUIPROJECT_API UAchievementSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable) 
	FAchievementProgressChange OnAchievementProgressUpdated;
	
	UPROPERTY(BlueprintAssignable) 
	FAchievementUnlock OnAchievementUnlocked;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAchievementRecord*> AchievementsRecords;
	
	UFUNCTION(BlueprintCallable)
	void AddProgress(int32 ID, int32 Amount);
	
	UFUNCTION(BlueprintPure)
	UAchievementRecord* GetAchievementRecord(int32 ID);
	
	UFUNCTION(BlueprintCallable)
	TSoftObjectPtr<UAchievementInfo> GetAchievementInfo(int32 ID);
	
	UFUNCTION(BlueprintCallable)
	void UnlockAchievement(int32 ID);
	
	UFUNCTION(BlueprintPure)
	bool IsUnlocked(int32 ID);
	
	UFUNCTION(BlueprintCallable)
	TArray<TSoftObjectPtr<UAchievementInfo>> GetAllAchievementInfos();
	
private:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	bool bEnableLogs = true;
	bool bEnableHiddenAchievements;
};
