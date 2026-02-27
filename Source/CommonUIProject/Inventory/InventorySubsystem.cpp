// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySubsystem.h"

#include "InventorySettings.h"

TArray<TSoftObjectPtr<UInventoryItem>> UInventorySubsystem::GetAllExistingItems()
{
	return UInventorySettings::GetConfig()->AllInventoryItems;
}
