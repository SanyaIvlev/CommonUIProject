#include "InventorySettings.h"

const UInventorySettings* UInventorySettings::GetConfig()
{
	return GetDefault<UInventorySettings>();
}