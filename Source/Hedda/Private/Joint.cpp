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
	if (!SkeletalMesh || !attachedMember)
	{
		return;
	}

	attachedMember->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	SkeletalMesh->SetSimulatePhysics(true);
	SkeletalMesh->SetAllBodiesBelowSimulatePhysics(boneName, true, true);
	SkeletalMesh->SetEnableGravity(true);

	FString messageError = FString::Printf(TEXT("%s has been dismembered"), *boneName.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, messageError);
}

