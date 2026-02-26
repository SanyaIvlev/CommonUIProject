#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AchievementSubsystemSettings.generated.h"

class UAchievementInfo;

UCLASS(Config=Game, defaultconfig, meta=(DisplayName="Achievement Subsystem Settings"))
class COMMONUIPROJECT_API UAchievementSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSoftObjectPtr<UAchievementInfo>> ExistingAchievements;
	
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly)
	bool bEnableLogs;
	
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly)
	bool bEnableHiddenAchievements;
};
