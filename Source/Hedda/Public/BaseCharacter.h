#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DamageTypeEnum.h"
#include "MemberTest.h"
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
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterFunction")
	void Death();
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	void RotateBody(float _deltaTime);
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	void RotateHead(FVector2D _rotationOffset);
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	void RotateArms(float _deltaTime);

	void InitializeCollider(FName _socketName, FName _boneName, int _index, float _maxHitPoints, bool _bCanBeDismember, bool _bAttachedToMember, bool _bCanBeUsed);

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UChildActorComponent>> membersFinals;
	/*
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UChildActorComponent>> membersTest;*/

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void DealDamage(float _amount);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void Heal(float _amount);
	UFUNCTION(BlueprintCallable, Category = "Rotation")
	const FVector2D GetHeadLookOffset() const;
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void FirstAttack();
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void SecondAttack();
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void Attack(int _weapon);

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USceneComponent* projectileSpawnPoint;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CharacterVariables")
	FName forarmSocketName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UWeapon*> weapons;
};
