#pragma once

#include "CoreMinimal.h"
#include "FNamedSound.h"
#include "Engine/DataAsset.h"
#include "USoundBank.generated.h"

UCLASS()
class HEDDA_API UUSoundBank : public UDataAsset
{
	GENERATED_BODY()
	
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundBank")
	TArray<FNamedSound> soundList;

	USoundBase* GetSoundByName(FName _SoundName) const;
};
