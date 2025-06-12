
#include "NiagaraSystemSubsystem.h"

void UNiagaraSystemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FStringAssetReference ParticleBankPath(TEXT("/Game/DataAssets/Particles/DA_ParticlesBank.DA_ParticlesBank"));
	ParticleBank = Cast<UParticleBank>(StaticLoadObject(UParticleBank::StaticClass(), nullptr, *ParticleBankPath.ToString()));

	if (!ParticleBank)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Cast returned null")));
	}
}

void UNiagaraSystemSubsystem::PlayParticle(FName _particleName, FVector _location, FRotator _rotation, USceneComponent* _parentComponent)
{
	if (!ParticleBank)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("The bank is missing")));
		return;
	}

	if (!_parentComponent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("The _parent component is missing")));
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Getting the NE")));
	UNiagaraSystem* particule = ParticleBank->GetParticuleByName(_particleName);
	if (particule)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(
			particule,
			_parentComponent,
			NAME_None,                          // Ou SocketName si nécessaire
			_location,
			_rotation,
			EAttachLocation::KeepRelativeOffset,
			true                                // AutoDestroy
		);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Played the NE")));
	}
}

