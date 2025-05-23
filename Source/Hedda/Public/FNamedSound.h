#pragma once

#include "CoreMinimal.h"
#include "FNamedSound.generated.h"

USTRUCT(BlueprintType)
struct FNamedSound
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	FName SoundName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* sound;
};