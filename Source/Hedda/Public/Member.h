#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Member.generated.h"

UCLASS()
class HEDDA_API UMember : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UMember();
	UFUNCTION(BlueprintCallable)
	const int GetHitPoint() const;

protected:
	void Heal(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void TakeDamage();

protected:
	int maxHitPoint;
	int currentHitPoint;
	float healTime;
	float currentHealtTime;
	
};
