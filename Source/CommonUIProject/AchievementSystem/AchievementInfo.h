#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AchievementInfo.generated.h"

UENUM(BlueprintType)
enum class EAchievementType : uint8
{
	Counter,
	Boolean,
	Hidden
};


UCLASS()
class COMMONUIPROJECT_API UAchievementInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AchievementInfo")
	int32 ID;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AchievementInfo")
	FName DisplayName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AchievementInfo")
	FText Description;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AchievementInfo")
	TSoftObjectPtr<UTexture2D> Icon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AchievementInfo")
	int32 TargetValue;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AchievementInfo")
	EAchievementType Type;
};
