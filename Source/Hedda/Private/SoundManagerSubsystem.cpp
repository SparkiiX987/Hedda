#include "SoundManagerSubsystem.h"
#include "USoundBank.h"
#include <Kismet/GameplayStatics.h>
#include "Components/AudioComponent.h" 
USoundManagerSubsystem::USoundManagerSubsystem()
{
	
}

void USoundManagerSubsystem::PlaySFX(FName _soundName, FVector _location)
{
	UWorld* world = GetWorld();
	if (world)
	{
		UUSoundBank* soundBank = Cast<UUSoundBank>(StaticLoadObject(UUSoundBank::StaticClass(), nullptr, TEXT("SoundBank'/Game/Audio/SoundBank.SoundBank'")));
		if (soundBank)
		{
			USoundBase* sound = soundBank->GetSoundByName(_soundName);
			if (sound)
			{
				UGameplayStatics::PlaySoundAtLocation(world, sound, _location);
			}
		}
	}
}

void USoundManagerSubsystem::PlayMusic(FName _soundName)
{
	UWorld* world = GetWorld();
	if (world)
	{
		UUSoundBank* soundBank = Cast<UUSoundBank>(StaticLoadObject(UUSoundBank::StaticClass(), nullptr, TEXT("SoundBank'/Game/Audio/SoundBank.SoundBank'")));
		if (soundBank)
		{
			USoundBase* sound = soundBank->GetSoundByName(_soundName);
			if (sound)
			{
				MusicAudioComponent = UGameplayStatics::SpawnSound2D(world, sound);
			}
		}
	}
}

void USoundManagerSubsystem::StopMusic()
{
	if (MusicAudioComponent)
	{
		MusicAudioComponent->Stop();
	}
}