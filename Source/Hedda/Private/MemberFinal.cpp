// Fill out your copyright notice in the Description page of Project Settings.


#include "MemberFinal.h"
#include "FPSProjectile.h"
#include "Components/ShapeComponent.h"
#include <Components/CapsuleComponent.h>

AMemberFinal::AMemberFinal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = GetCollisionComponent();

	if (Collision)
	{
		Collision->SetHiddenInGame(false);
		Collision->SetVisibility(true);
	}
}

void AMemberFinal::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (UCapsuleComponent* Capsule = Cast<UCapsuleComponent>(Collision))
	{
		Capsule->SetCapsuleSize(radius, halfHeight);
	}
}

void AMemberFinal::TakeDamage(float _amount)
{
	currentHitPoint += _amount;
}

const float AMemberFinal::GetHealthPoints() const
{
	return maxHitPoint - currentHitPoint;
}

void AMemberFinal::Dismember()
{
	if (bCanBeDismembered)
	{
		bodyMesh->HideBoneByName(AttachedBoneName, EPhysBodyOp::PBO_None);
		bCanBeUsed = false;
	}
}

/*void AMemberFinal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPSProjectile* projectile = Cast<AFPSProjectile>(OtherActor);
	if (projectile)
	{
		baseCharacter->TakeDamage(projectile->damage * multiplacaterDamage);
		if (GetHealthPoints() <= 0)
		{
			Dismember();
			baseCharacter->membersFinals[baseCharacter->membersFinals.IndexOfByKey(this)]->DestroyChildActor();
		}
	}
}*/
