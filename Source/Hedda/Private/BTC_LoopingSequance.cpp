// Fill out your copyright notice in the Description page of Project Settings.


#include "BTC_LoopingSequance.h"

UBTC_LoopingSequance::UBTC_LoopingSequance()
{
	NodeName = "Looping Sequence";
}

int32 UBTC_LoopingSequance::GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild,
                                                EBTNodeResult::Type LastResult) const
{
	const int32 NumChildren = GetChildrenNum();


	if (NumChildren == 0)
	{
		return BTSpecialChild::ReturnToParent;
	}

	if (IterationCount >= MaxIterationsPerChild)
	{
		IterationCount = 0;
		CurrentChild = (CurrentChild + 1) % NumChildren;
	}

	IterationCount++;
	return CurrentChild;
}
