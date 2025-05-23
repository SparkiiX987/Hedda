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
	const float GetHealPoints() const;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float _amount);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	float maxHealthPoint = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	float currentHealthPoint = 5.0f;
	
};
