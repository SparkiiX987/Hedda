#include "Member.h"

void UMember::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UMember::UMember()
{
	PrimaryComponentTick.bCanEverTick = true;
}

const float UMember::GetHealPoints() const
{
	return currentHealthPoint;
}

void UMember::TakeDamage(float _amount)
{
	if(currentHealthPoint <= 0)
	{
		return;
	}

	currentHealthPoint -= _amount;

	FString messageError = FString::Printf(TEXT("%s has take damage"), *GetOwner()->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, messageError);
}

