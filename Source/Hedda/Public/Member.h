#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include <Components/CapsuleComponent.h>
#include "Member.generated.h"

UCLASS(Blueprintable, BlueprintType)
class HEDDA_API UMember : public UPrimitiveComponent
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	float maxHitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	float currentHitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	FName AttachedBoneName;
	UPROPERTY(EditAnywhere, Category = "Member")
	UCapsuleComponent* Collider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	bool bCanBeDismembered;

public:
	UMember();
	UFUNCTION(BlueprintCallable, Category = "Member")
	void TakeDamage(float _amount);
	UFUNCTION(BlueprintCallable, Category = "Member")
	const float GetHealPoints() const;
	UFUNCTION(BlueprintCallable, Category = "Member")
	void Dismember();	
};
