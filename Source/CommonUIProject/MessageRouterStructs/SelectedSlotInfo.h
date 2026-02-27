#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "SelectedSlotInfo.generated.h"

class UInventoryItem;

USTRUCT(BlueprintType)
struct FSelectedSlotInfo
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryItem* ItemInfo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsItemEquipped;
};
