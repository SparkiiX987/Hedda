#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::RotateBody(float _deltaTime)
{
	FRotator CurrentControlRot = GetControlRotation();

	float TargetYaw = CurrentControlRot.Yaw + HeadLookOffset.X;

	FRotator TargetRot(0.f, TargetYaw, 0.f);
	FRotator SmoothedRot = FMath::RInterpTo(CurrentControlRot, TargetRot, _deltaTime, BodyRotationInterpSpeed);

	Controller->SetControlRotation(SmoothedRot);

	float DeltaYaw = FRotator::NormalizeAxis(SmoothedRot.Yaw - CurrentControlRot.Yaw);
	HeadLookOffset.X -= DeltaYaw;
}

void ABaseCharacter::RotateHead(FVector2D _rotationOffset)
{
	HeadLookOffset += _rotationOffset;
	FMath::Clamp(HeadLookOffset.X, -60.0f, 60.0f);
	FMath::Clamp(HeadLookOffset.Y, -40.0f, 15.0f);
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateBody(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::DealDamage(float _amount)
{
	healPoint -= _amount;
	if (healPoint <= 0)
	{
		/*if (GetClass()->IsFunctionImplementedInScript(TEXT("Death")))
		{
		}*/
			Death();
	}
}

void ABaseCharacter::Heal(float _amount)
{
	healPoint += _amount;
	if (healPoint > maxHealPoint)
	{
		healPoint = maxHealPoint;
	}
}

const EFaction ABaseCharacter::GetFaction() const
{
	return faction;
}

const FVector2D ABaseCharacter::GetHeadLookOffset() const
{
	return HeadLookOffset;
}

void ABaseCharacter::FirstAttack()
{
	UWorld* world = GetWorld();

	if (!world) return;

	if (weapons.Num() > 0 && weapons[0] && weapons[0]->projectile)
	{		
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		TSubclassOf<AActor> ProjectileClass = weapons[0]->projectile;

		AActor* projectile = world->SpawnActor<AActor>(ProjectileClass,GetActorLocation(), GetActorRotation(), SpawnParams);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Shoot FW"));
	}
	else 
	{
		
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("First weapon invalid"));
	}
}

void ABaseCharacter::SecondAttack()
{
	UWorld* world = GetWorld();

	if (!world) return;

	if (weapons.Num() > 0 && weapons[1] && weapons[1]->projectile)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		TSubclassOf<AActor> ProjectileClass = weapons[1]->projectile;

		AActor* projectile = world->SpawnActor<AActor>(ProjectileClass, GetActorLocation(), GetActorRotation(), SpawnParams);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Shoot SW"));
	}
	else 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Second weapon invalid"));
	}
}
