// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTask_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class HEDDA_API UBTTask_Shoot : public UBTTask_BlueprintBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Blueprintable)
	bool bHasAmmo;
	
};
