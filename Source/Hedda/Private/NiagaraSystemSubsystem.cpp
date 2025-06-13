
#include "NiagaraSystemSubsystem.h"

void UNiagaraSystemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FStringAssetReference ParticleBankPath(TEXT("/Game/DataAssets/Particles/DA_ParticlesBank.DA_ParticlesBank"));
	ParticleBank = Cast<UParticleBank>(StaticLoadObject(UParticleBank::StaticClass(), nullptr, *ParticleBankPath.ToString()));

	if (!ParticleBank)
	{
	}
}

void UNiagaraSystemSubsystem::PlayParticle(FName _particleName, FVector _location, FRotator _rotation, USceneComponent* _parentComponent)
{
	if (!ParticleBank)
	{
		return;
	}

	UNiagaraSystem* particule = ParticleBank->GetParticuleByName(_particleName);

	if (!_parentComponent)
	{
		if(particule){
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(
				GetWorld(),
				particule,
				_location,
				_rotation
			);
		}
		return;
	}

	if (particule)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(
			particule,
			_parentComponent,
			NAME_None,                          
			_location,
			_rotation,
			EAttachLocation::KeepRelativeOffset,
			true                               
		);
	}
}

