// Fill out your copyright notice in the Description page of Project Settings.


#include "MemberFinal.h"
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
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("current hit points: %f"), currentHitPoint));
}

const float AMemberFinal::GetHealthPoints() const
{
	return maxHitPoint - currentHitPoint;
}

void AMemberFinal::Dismember()
{
	if (bCanBeDismembered)
	{
		FVector Impulse = FVector(0.0f, 0.0f, 0.0f);
		FVector HitLocation = GetActorLocation();

		if (bCanBeDismembered && IsValid(secondMember))
		{
			secondMember->Dismember();
		}

		bodyMesh->BreakConstraint(Impulse, HitLocation, AttachedBoneName);

		memberMainStaticMesh->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
		memberMainStaticMesh->SetSimulatePhysics(true);
		memberMainStaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		memberMainStaticMesh->SetEnableGravity(true);
		bodyMesh->SetAllBodiesBelowSimulatePhysics(AttachedBoneName, true, true);

		bCanBeUsed = false;
	}
}
