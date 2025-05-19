#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DamageTypeEnum.h"
#include "Joint.h"
#include "Member.h"
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

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void DealDamage(float _amount);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void Heal(float _amount);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	const EFaction GetFaction() const;
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterFunction")
	void Death();

protected:
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
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UJoint*> joints;
};
