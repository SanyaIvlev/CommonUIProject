// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "InventorySubsystem.generated.h"

class UInventoryItem;
/**
 * 
 */
UCLASS()
class COMMONUIPROJECT_API UInventorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	UFUNCTION(BlueprintPure)
	TArray<UInventoryItem*> GetAllExistingItems();
private:
	TArray<UInventoryItem*> AllItems; 
};
