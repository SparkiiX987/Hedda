// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BTC_LoopingSequance.generated.h"

/**
 * 
 */
UCLASS()
class HEDDA_API UBTC_LoopingSequance : public UBTCompositeNode
{
	GENERATED_BODY()

public:
	UBTC_LoopingSequance();
	UPROPERTY(Category = "Iteration", EditAnywhere, meta = (ClampMin = "0.0", UIMin = "0.0"))
	mutable int32 IterationCount;
	mutable int32 CurrentChild;
	UPROPERTY(Category = "Iteration", EditAnywhere, meta = (ClampMin = "0.0", UIMin = "0.0"))
	int32 MaxIterationsPerChild;

protected:
	virtual int32 GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild,
	                                  EBTNodeResult::Type LastResult) const override;
	void AddChildNode(UBTCompositeNode* ChildNode);
};
