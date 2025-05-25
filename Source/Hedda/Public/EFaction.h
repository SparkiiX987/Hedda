#pragma once

#include "CoreMinimal.h"
#include "EFaction.generated.h"

UENUM(BlueprintType)
enum class EFaction : uint8
{
    Mage     UMETA(DisplayName = "Mage"),
    Mecha    UMETA(DisplayName = "Mecha"),
    Neutral  UMETA(DisplayName = "Neutral")
};
