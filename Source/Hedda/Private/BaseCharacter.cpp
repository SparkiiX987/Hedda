#include "BaseCharacter.h"
#include "MemberFinal.h"
#include "Components/ShapeComponent.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	lightProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("lightProjectileSpawnPoint"));
	lightProjectileSpawnPoint->SetupAttachment(GetMesh(),"lightProjectilesSocket");

	heavyProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("heavyProjectileSpawnPoint"));
	heavyProjectileSpawnPoint->SetupAttachment(GetMesh(), "heavyProjectilesSocket");

	for (int i = 0; i < 7; i++) {
		UChildActorComponent* member = CreateDefaultSubobject<UChildActorComponent>(FName(*FString::Printf(TEXT("MemberFinal_%d"), i)));
		member->SetChildActorClass(AMemberFinal::StaticClass());
		membersFinals.Add(member);
	}

	InitializeCollider("CabineSocket", "cabin", 0, 20, false, false, false);
	InitializeCollider("BatterySocket", "backdoor_tube_1", 1, 5, false, false, false);
	InitializeCollider("HeadSocket", "headbone", 2, 1, false, false, false);
	InitializeCollider("LeftArmSocket", "arm_r", 3, 5, true, true, false);
	InitializeCollider("ForearmLeftSocket", "forearm_r", 4, 5, true, false, true);
	InitializeCollider("RightArmSocket", "arm_l", 5, 5, true, true, false);
	InitializeCollider("ForearmRightSocket", "forearm_l", 6, 5, true, false, true);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::RotateBody(float _deltaTime)
{
	if (Controller == nullptr)
		return;
	FRotator CurrentControlRot = GetControlRotation();

	float TargetYaw = CurrentControlRot.Yaw + headLookOffset.X;

	FRotator TargetRot(0.f, TargetYaw, 0.f);
	FRotator SmoothedRot = FMath::RInterpTo(CurrentControlRot, TargetRot, _deltaTime, bodyRotationInterpSpeed);

	Controller->SetControlRotation(SmoothedRot);

	float DeltaYaw = FRotator::NormalizeAxis(SmoothedRot.Yaw - CurrentControlRot.Yaw);
	headLookOffset.X -= DeltaYaw;
}

void ABaseCharacter::RotateHead(FVector2D _rotationOffset)
{
	headLookOffset += _rotationOffset;
	headLookOffset.X = FMath::Clamp(headLookOffset.X, -60.0f, 60.0f);
	headLookOffset.Y = FMath::Clamp(headLookOffset.Y, -40.0f, 15.0f);
}

void ABaseCharacter::RotateArms(float _deltaTime)
{
	float TargetPitch = headLookOffset.Y;
	armLookOffsetPitch = FMath::FInterpTo(armLookOffsetPitch, TargetPitch, _deltaTime, armsRotationInterpSpeed);
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

void ABaseCharacter::Heal(float _amount)
{
	healPoint += _amount;
	if (healPoint > maxHealPoint)
	{
		healPoint = maxHealPoint;
	}
}

const FVector2D ABaseCharacter::GetHeadLookOffset() const
{
	return headLookOffset;
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

		TSubclassOf<AFPSProjectile> ProjectileClass = weapons[0]->projectile;
		float projectileSpread = FMath::Clamp(weapons[0]->spread, 0.0f, 100.0f);
		float projectileShoot = FMath::Clamp(weapons[0]->bulletNumber, 0.0f, 100.0f);

		const float coneHalfAngleRad = FMath::DegreesToRadians(projectileSpread);
		FVector forwardVector = lightProjectileSpawnPoint->GetForwardVector();
		FVector spawnLocation = lightProjectileSpawnPoint->GetComponentLocation();
		FRotator forwardRotator = forwardVector.Rotation();

		for (int i = 0; i < projectileShoot; i++)
		{
			if (projectileSpread == 0)
			{
				AFPSProjectile* projectile = world->SpawnActor<AFPSProjectile>(
					ProjectileClass, spawnLocation, forwardRotator, SpawnParams);
				if (projectile == nullptr) { return; }
				projectile->characterFrom = this;
			}
			else
			{
				FVector randomDir = FMath::VRandCone(forwardVector, coneHalfAngleRad);
				FRotator spawnRotation = randomDir.Rotation();
				AFPSProjectile* projectile = world->SpawnActor<AFPSProjectile>(
					ProjectileClass, spawnLocation, spawnRotation, SpawnParams);
				if (projectile == nullptr) { return; }
				projectile->characterFrom = this;
			}
		}
	}
}

void ABaseCharacter::SecondAttack()
{
	UWorld* world = GetWorld();

	if (!world) return;

	if (weapons.Num() > 0 && weapons[1] && targetingBeacon != nullptr) 
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
				
		FVector forwardVector = lightProjectileSpawnPoint->GetForwardVector();
		FVector spawnLocation = lightProjectileSpawnPoint->GetComponentLocation();
		FRotator forwardRotator = forwardVector.Rotation();

		AFPSProjectile* projectile = world->SpawnActor<AFPSProjectile>(
			targetingBeacon, spawnLocation, forwardRotator, SpawnParams);
		if (projectile == nullptr) { return; }
		projectile->characterFrom = this;
	}
}

void ABaseCharacter::InitializeCollider(FName _socketName, FName _boneName, int _index, float _maxHitPoints, bool _bCanBeDismember, bool _bAttachedToMember, bool _bCanBeUsed)
{
	membersFinals[_index]->SetupAttachment(GetMesh(), _socketName);
}
