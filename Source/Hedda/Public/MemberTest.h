// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerCapsule.h"
#include "Components/ShapeComponent.h"
#include "Components/CapsuleComponent.h"
#include "MemberTest.generated.h"

UCLASS()
class HEDDA_API AMemberTest : public ATriggerCapsule
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemberTest();
	UFUNCTION(BlueprintCallable, Category = "Member")
	void TakeDamage(float _amount);
	UFUNCTION(BlueprintCallable, Category = "Member")
	const float GetHealthPoints() const;
	UFUNCTION(BlueprintCallable, Category = "Member")
	void Dismember();

	virtual void OnConstruction(const FTransform& Transform) override;

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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	USkeletalMeshComponent* bodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	UStaticMeshComponent* memberMainStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	AMemberTest* secondMember;
};
