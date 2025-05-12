#include "Member.h"

void UMember::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Heal(DeltaTime);
}

UMember::UMember()
{
	PrimaryComponentTick.bCanEverTick = true;

}

const int UMember::GetHitPoint() const
{
	return currentHitPoint;
}

void UMember::Heal(float _deltaTime)
{
	if (currentHitPoint >= maxHitPoint)
	{
		return;
	}

	if (currentHealtTime < healTime)
	{
		currentHealtTime += _deltaTime;
		return;
	}

	currentHitPoint++;
	if (currentHitPoint >= maxHitPoint)
	{
		currentHitPoint = maxHitPoint;
		currentHealtTime = 0;
	}
}

void UMember::TakeDamage()
{
	if(currentHitPoint <= 0)
	{
		return;
	}

	currentHitPoint--;
}

