// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Engine/DeveloperSettings.h"
#include "InventorySettings.generated.h"

/**
 * 
 */
UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Inventory Settings"))
class COMMONUIPROJECT_API UInventorySettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	static const UInventorySettings* GetConfig();
	
	UPROPERTY(Config, EditDefaultsOnly, Category="Items", BlueprintReadOnly)
	TArray<TSoftObjectPtr<UInventoryItem>> AllInventoryItems;
};
