#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "InventoryItem.generated.h"

UCLASS()
class COMMONUIPROJECT_API UInventoryItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly) 
	FGameplayTag ItemTag;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly) 
	FText DisplayName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly) 
	FText Description;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly) 
	TSoftObjectPtr<UTexture2D> Icon;
};
