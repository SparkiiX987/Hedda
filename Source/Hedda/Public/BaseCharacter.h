#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DamageTypeEnum.h"
#include "Joint.h"
#include "Member.h"
#include "BaseCharacter.generated.h"

UENUM(BlueprintType)
enum class Faction : uint8
{
	Mage	UMETA(DisplayName = "Mage"),
	Mecha	UMETA(DisplayName = "Mecha"),
	Neurtal UMETA(DisplayName = "Neutral")
};

UCLASS()
class HEDDA_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void HealCHP(float _deltaTime);

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void DealDamage(UDamageTypeEnum _damageType, float _amount, float _time);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void Heal(float _amount);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void AddStamina(float _amount);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	void SetTimeBeforeHealing(float _time);
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	const Faction GetFaction() const;
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	const float GetStaimana() const;
	UFUNCTION(BlueprintCallable, Category = "CharacterFunction")
	const float GetMana() const;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float THP;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float CHP;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float RHP;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float stamina;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float staminaMax;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float movementSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float rotationSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float mana;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	Faction faction;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float CHPHealthSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float timeBeforeHealing;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float healingCooldown;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	float currentHealingCooldown;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UMember*> members;
	UPROPERTY(BlueprintReadWrite, Category = "CharacterVariables")
	TArray<UJoint*> joints;
};
