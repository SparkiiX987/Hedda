#include "Joint.h"

UJoint::UJoint()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UJoint::BeginPlay()
{
	Super::BeginPlay();
	AActor* owner = GetOwner();
	if (owner)
	{
		SkeletalMesh = owner->FindComponentByClass<USkeletalMeshComponent>();
	}
	
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

