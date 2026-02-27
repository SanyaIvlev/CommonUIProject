#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "UAchievementRecord.generated.h"

UCLASS()
class COMMONUIPROJECT_API UAchievementRecord : public UObject
{
	GENERATED_BODY()
	
public:
	bool bIsUnlocked;
	
	void Initialize(int32 TargetProgress);
	
	UFUNCTION(BlueprintPure)
	int32 GetTargetProgress() const;
	
	UFUNCTION(BlueprintPure)
	int32 GetCurrentProgress() const;
	
	UFUNCTION(BlueprintCallable)
	void AddProgress(int32 ProgressAdded);
	
	UFUNCTION(BlueprintCallable)
	void ResetProgress();
	
private:
	UPROPERTY(VisibleAnywhere)
	int32 TargetProgress;
	
	UPROPERTY(VisibleAnywhere)
	int32 ProgressCount;
};
