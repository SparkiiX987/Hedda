#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float THP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float CHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float RHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float stamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float staminaMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float movementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float rotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	float mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterVariables)
	Faction faction;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//void TakeDamage();

};
