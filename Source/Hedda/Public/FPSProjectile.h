#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Weapon.h"
#include "FPSProjectile.generated.h"

class ABaseCharacter;

UCLASS()
class HEDDA_API AFPSProjectile : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFPSProjectile();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Sphere collision component

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile)
    USphereComponent* sphereComponent;

    // Projectile movement component
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
    UProjectileMovementComponent* projectileMovementComponent;

    UPROPERTY(BlueprintReadWrite, Category = "Player")
    AActor* characterFrom;

    // Projectile mesh
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile)
    UStaticMeshComponent* projectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracteristics")
    float maxSpeed = 0.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracteristics")
    float initialSpeed = 0.0f;
	float damage = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracteristics")
	float size = 10.0f;
    // Function that is called when the projectile hits something.
    UFUNCTION(BlueprintCallable, Category = "Rotation")
    void OnProjectileHit(AActor* _otherActor, UPrimitiveComponent* _otherComponent);
};