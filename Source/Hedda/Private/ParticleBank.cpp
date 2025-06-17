// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleBank.h"
#include "Algo/Find.h"

UNiagaraSystem* UParticleBank::GetParticuleByName(FName _particleName) const
{
    const FNamedParticule* Found = Algo::FindByPredicate(fNamedParticules, [_particleName](const FNamedParticule& Entry)
    {
        return Entry.particleName == _particleName;
    });

    return Found ? Found->particle : nullptr;
}