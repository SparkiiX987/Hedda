// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerCapsule.h"
#include "MemberFinal.generated.h"


UCLASS()
class HEDDA_API AMemberFinal : public ATriggerCapsule
{
	GENERATED_BODY()
	
public:
	AMemberFinal();
	virtual void OnConstruction(const FTransform& Transform) override;
	UFUNCTION(BlueprintCallable, Category = "Member")
	void TakeDamage(float _amount);
	UFUNCTION(BlueprintCallable, Category = "Member")
	const float GetHealthPoints() const;
	UFUNCTION(BlueprintCallable, Category = "Member")
	void Dismember();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	USkeletalMeshComponent* bodyMesh;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UShapeComponent* Collision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	float maxHitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	float currentHitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	FName AttachedBoneName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	bool bCanBeDismembered;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	bool bIsAttachedToAMember;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	bool bCanBeUsed;
	UPROPERTY(EditAnywhere, Category = "Capsule")
	float radius;
	UPROPERTY(EditAnywhere, Category = "Capsule")
	float halfHeight;
};
