#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DamageTypeEnum.h"
#include "Joint.h"
#include "Member.h"
#include "Weapon.h"
#include "FPSProjectile.h"
#include "BaseCharacter.generated.h"


UCLASS()
class HEDDA_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CharacterFunction")
	void Death();
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	void RotateBody(float _deltaTime);
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	void RotateHead(FVector2D _rotationOffset);
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	void RotateArms(float _deltaTime);

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CharacterFunction")
	void DealDamage(float _amount); 
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void Heal(float _amount);
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	const FVector2D GetHeadLookOffset() const;
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void FirstAttack();
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void SecondAttack();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	FVector2D headLookOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float bodyRotationInterpSpeed = 6.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float armsRotationInterpSpeed = 6.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")	
	float armLookOffsetPitch;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float maxHealPoint;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float healPoint;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float movementSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float headRotationSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float bodyRotationSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UMember*> members;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* lightProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* heavyProjectileSpawnPoint;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	FName forarmSocketName;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UJoint*> joints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UWeapon*> weapons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	TSubclassOf<AFPSProjectile> targetingBeacon;
};
