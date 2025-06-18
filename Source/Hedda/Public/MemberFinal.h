// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerCapsule.h"
#include "BaseCharacter.h"
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
	UFUNCTION(BlueprintCallable, Category = "Member")
	void OnFallenMemberHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	USkeletalMeshComponent* bodyMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	ABaseCharacter* baseCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	AMemberFinal* attachedMember;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	UStaticMesh* memberMesh;
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool playedOnce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Member")
	float multiplacaterDamage;
	UPROPERTY(EditAnywhere, Category = "Capsule")
	float radius;
	UPROPERTY(EditAnywhere, Category = "Capsule")
	float halfHeight;
};