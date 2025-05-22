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

UENUM(BlueprintType)
enum class EFaction : uint8
{
	Mage	UMETA(DisplayName = "Mage"),
	Mecha	UMETA(DisplayName = "Mecha"),
	Neutral UMETA(DisplayName = "Neutral")
};

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

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void DealDamage(float _amount);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void Heal(float _amount);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	const EFaction GetFaction() const;
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
	FVector2D HeadLookOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float BodyRotationInterpSpeed = 6.f;
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
	EFaction faction;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UMember*> members;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UMember* forearm;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UJoint*> joints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UWeapon*> weapons;
};
