// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "FNamedParticule.generated.h"

USTRUCT(BlueprintType)
struct FNamedParticule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particule")
	FName particleName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particule")
	UNiagaraSystem* particle;
};
