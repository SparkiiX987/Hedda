#include "SoundManagerSubsystem.h"
#include "USoundBank.h"
#include <Kismet/GameplayStatics.h>
#include "Components/AudioComponent.h" 

void USoundManagerSubsystem::PlaySFX(FName _soundName, FVector _location)
{
	UWorld* world = GetWorld();
	if (world)
	{
		USoundBase* sound = soundBank->GetSoundByName(_soundName);
		if (sound)
		{
			UGameplayStatics::PlaySoundAtLocation(world, sound, _location);
		}
	}
}

void USoundManagerSubsystem::PlayMusic(FName _soundName)
{
	UWorld* world = GetWorld();
	if (world)
	{
		USoundBase* sound = soundBank->GetSoundByName(_soundName);
		if (sound)
		{
			musicAudioComponent = UGameplayStatics::SpawnSound2D(world, sound);
		}
	}
}

void USoundManagerSubsystem::StopMusic()
{
	if (musicAudioComponent)
	{
		musicAudioComponent->Stop();
	}
}