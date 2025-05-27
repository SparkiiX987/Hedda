#include "Member.h"

UMember::UMember()
{
	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->SetupAttachment(this);
	SetCollisionProfileName(TEXT("Member"));
}

void UMember::TakeDamage(float _amount)
{
	currentHitPoint -= _amount;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Called TakeDamage()"));
}

const float UMember::GetHealPoints() const
{
	return currentHitPoint;
}

void UMember::Dismember()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Called Dismember"));
}
