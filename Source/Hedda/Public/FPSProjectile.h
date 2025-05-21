
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "FPSProjectile.generated.h"

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
    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    USphereComponent* sphereComponent;

    // Projectile movement component
    UPROPERTY(VisibleAnywhere, Category = Movement)
    UProjectileMovementComponent* projectileMovementComponent;

    // Function that initializes the projectile's velocity in the shoot direction.
	UFUNCTION(BlueprintImplementableEvent, Category = "Projectile")
    void FireInDirection(const FVector& _shootDirection);

    // Projectile mesh
    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    UStaticMeshComponent* projectileMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float damage = 20.0f;

    // Function that is called when the projectile hits something.
    UFUNCTION()
    void OnImpact(UPrimitiveComponent* _hitComponent, AActor* _otherActor, UPrimitiveComponent* _otherComponent, FVector _normalImpulse, const FHitResult& _hit);
};