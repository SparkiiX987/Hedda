#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HealCHP(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::DealDamage(UDamageTypeEnum _damageType, float _amount, float _time)
{
	SetTimeBeforeHealing(_time);
	currentHealingCooldown = healingCooldown;
	switch (_damageType)
	{
		case UDamageTypeEnum::Blunt:
			RHP -= (_amount + (0.2f * _amount));
			CHP = RHP - (0.2f * _amount);
			stamina -= 0.2f * _amount;
			break;

		case UDamageTypeEnum::DOT:
			RHP -= _amount;
			CHP = RHP - (1 - (0.2f * _amount));
			break;
		default:
			break;
	}
}

void ABaseCharacter::HealCHP(float _deltaTime)
{
	if(CHP >= RHP)
	{
		return;
	}

	if (timeBeforeHealing > 0)
	{
		timeBeforeHealing -= _deltaTime;
		return;
	}

	if (currentHealingCooldown > 0)
	{
		currentHealingCooldown -= _deltaTime;
		return;
	}

	CHP += 1;
	currentHealingCooldown = healingCooldown;
}

void ABaseCharacter::Heal(float _amount)
{
	RHP += _amount;
	CHP = RHP;
}

void ABaseCharacter::AddStamina(float _amount)
{
	if (stamina + _amount == staminaMax)
	{
		stamina = staminaMax;
		return;
	}

	stamina += _amount;

	if (stamina < 0)
	{
		stamina = 0;
	}
}

const Faction ABaseCharacter::GetFaction() const
{
	return faction;
}

void ABaseCharacter::SetTimeBeforeHealing(float _time)
{
	timeBeforeHealing = _time;
}

const float ABaseCharacter::GetStaimana() const
{
	return stamina;
}

const float ABaseCharacter::GetMana() const
{
	return mana;
}
