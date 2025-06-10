// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ParticleBank.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystemSubsystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class HEDDA_API UNiagaraSystemSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	public :

		UFUNCTION(BlueprintCallable, Category = "NiagaraSystem")
		void PlayParticle(FName _particleName, FVector _location, FRotator _rotation, USceneComponent* _parentComponent);
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NiagaraSystem")
		UParticleBank* ParticleBank;
};
