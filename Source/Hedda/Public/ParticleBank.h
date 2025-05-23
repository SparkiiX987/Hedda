// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NiagaraSystem.h"
#include "FNamedParticule.h"
#include "ParticleBank.generated.h"

UCLASS()
class HEDDA_API UParticleBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UNiagaraSystem* GetParticuleByName(FName _particleName) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FNamedParticule> fNamedParticules;
};