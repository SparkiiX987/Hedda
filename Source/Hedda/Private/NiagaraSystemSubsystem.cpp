
#include "NiagaraSystemSubsystem.h"


void UNiagaraSystemSubsystem::PlayParticle(FName _particleName, FVector _location, FRotator _rotation, USceneComponent* _parentComponent)
{
	if (!ParticleBank || !_parentComponent)
	{
		return;
	}

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
	}
}