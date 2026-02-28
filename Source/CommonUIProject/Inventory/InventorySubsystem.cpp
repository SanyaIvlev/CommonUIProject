// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySubsystem.h"

#include "InventorySettings.h"

void UInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	TArray<TSoftObjectPtr<UInventoryItem>> ItemsSoftArray = UInventorySettings::GetConfig()->AllInventoryItems;
	
	for (auto Item : ItemsSoftArray)
	{
		UInventoryItem* InventoryItem = Item.LoadSynchronous();
		AllItems.Add(InventoryItem);
	}
}

TArray<UInventoryItem*> UInventorySubsystem::GetAllExistingItems()
{
	return AllItems;
}
