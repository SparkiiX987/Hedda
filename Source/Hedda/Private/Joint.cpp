#include "Joint.h"

UJoint::UJoint()
{
	PrimaryComponentTick.bCanEverTick = true;
	SkeletalMesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
}


void UJoint::BeginPlay()
{
	Super::BeginPlay();

	
}


void UJoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UJoint::Dismember()
{
	if(attachedMember->GetHitPoint() > 0)
	{
		return;
	}

	if (!SkeletalMesh)
	{
		return;
	}

	SkeletalMesh->SetSimulatePhysics(true);
	SkeletalMesh->SetAllBodiesBelowSimulatePhysics(boneName, true, true);
	SkeletalMesh->SetEnableGravity(true);
}

