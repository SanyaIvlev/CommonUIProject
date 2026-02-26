#include "UAchievementRecord.h"

void UAchievementRecord::Initialize(int32 TargetValue)
{
	this->TargetProgress = TargetValue;
	ProgressCount = 0;
	bIsUnlocked = false;
}

int32 UAchievementRecord::GetTargetProgress() const
{
	return TargetProgress;
}

int32 UAchievementRecord::GetCurrentProgress() const
{
	return ProgressCount;
}

void UAchievementRecord::AddProgress(int32 ProgressAdded)
{
	ProgressCount += ProgressAdded;
	
	if (ProgressCount >= TargetProgress)
	{
		bIsUnlocked = true;
	}
}

void UAchievementRecord::ResetProgress()
{
	ProgressCount = 0;
	bIsUnlocked = false;
}
