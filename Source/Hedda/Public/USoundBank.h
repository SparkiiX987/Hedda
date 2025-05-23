#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "USoundBank.generated.h"

UCLASS()
class HEDDA_API UUSoundBank : public UDataAsset
{
	GENERATED_BODY()
	
public :
	USoundBase* GetSoundByName(FName _SoundName) const;
};
