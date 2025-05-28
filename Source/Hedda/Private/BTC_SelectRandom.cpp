// Fill out your copyright notice in the Description page of Project Settings.


#include "BTC_SelectRandom.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTC_SelectRandom::UBTC_SelectRandom()
{
	NodeName = "Random Choice 50/50";
}

int32 UBTC_SelectRandom::GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const
{
	if (PrevChild == INDEX_NONE)
	{
		// 1 chance sur 2 : 0 ou 1
		const int32 RandomIndex = FMath::RandRange(0, GetChildrenNum() - 1);
		return FMath::Clamp(RandomIndex, 0, GetChildrenNum() - 1);
	}

	// Après avoir exécuté un enfant, on revient au parent
	return BTSpecialChild::ReturnToParent;
}
