// Fill out your copyright notice in the Description page of Project Settings.


#include "MemberFinal.h"
#include "FPSProjectile.h"
#include "Engine/StaticMeshActor.h"
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
		if (bIsAttachedToAMember && attachedMember)
		{
			attachedMember->Dismember();
		}
		if (memberMesh) {
			AStaticMeshActor* fallenMember = GetWorld()->SpawnActor<AStaticMeshActor>(
				AStaticMeshActor::StaticClass(),
				GetActorLocation(),
				GetActorRotation()
			);

			if (fallenMember)
			{
				fallenMember->GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				fallenMember->GetStaticMeshComponent()->SetSimulatePhysics(true);
				fallenMember->GetStaticMeshComponent()->SetEnableGravity(true);
				fallenMember->SetMobility(EComponentMobility::Movable);
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Finished Spawning member"));
				fallenMember->GetStaticMeshComponent()->SetStaticMesh(memberMesh);
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Finished setting mesh"));
			}
		}
		bodyMesh->HideBoneByName(AttachedBoneName, EPhysBodyOp::PBO_None);
		bCanBeUsed = false;
		Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

