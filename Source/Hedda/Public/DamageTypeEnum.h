#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EDamageTypeEnum : uint8
{
	Cut		UMETA(DisplayName = "Cut"),
	Blunt	UMETA(DisplayName = "Blunt"),
	DOT		UMETA(DisplayName = "DOT")
};
