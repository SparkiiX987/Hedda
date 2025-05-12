#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DamageTypeEnum.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float THP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float CHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float RHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float stamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float staminaMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float movementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float rotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	Faction faction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float CHPHealthSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float timeBeforeHealing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float healingCooldown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterVariables")
	float currentHealingCooldown;

};
