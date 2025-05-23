#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SoundManagerSubsystem.generated.h"

UCLASS()
class HEDDA_API USoundManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundBank")
	UAudioComponent* MusicAudioComponent;

public :
	USoundManagerSubsystem();

	UFUNCTION(BlueprintCallable, Category = "SoundManager")
	void PlaySFX(FName _soundName, FVector _location);
	UFUNCTION(BlueprintCallable, Category = "SoundManager")
	void PlayMusic(FName _soundName);
	UFUNCTION(BlueprintCallable, Category = "SoundManager")
	void StopMusic();
};
