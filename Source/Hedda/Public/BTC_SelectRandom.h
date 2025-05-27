// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BTC_SelectRandom.generated.h"

/**
 * 
 */
UCLASS()
class HEDDA_API UBTC_SelectRandom : public UBTCompositeNode
{
GENERATED_BODY()
	
public:
	UBTC_SelectRandom();

protected:
	virtual int32 GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const override;

};
