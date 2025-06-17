#pragma once

#include "NiagaraSystem.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Weapon.generated.h"

class AFPSProjectile;

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	LightArtillery	UMETA(DisplayName = "Light Artillery"),
	HeavyArtillery	UMETA(DisplayName = "Heavy Artillery"),
};

UCLASS()
class HEDDA_API UWeapon : public UDataAsset
{
	GENERATED_BODY()

	public : 
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		FString weaponName;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		EWeaponType weaponType;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		float damage;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		float attackSpeed;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		float reloadTime;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		int bulletNumber;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		int ammo;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		float spread;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
		UNiagaraSystem* muzzleParticle;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TSubclassOf<AFPSProjectile> projectile;
};
