#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	projectileSpawnPoint->SetupAttachment(GetMesh(),"ProjectilesSocket");

	//Head
	headMember = CreateDefaultSubobject<UMember>(TEXT("Head"));
	headMember->SetupAttachment(GetMesh(), "HeadSocket");
	headMember->SetRelativeLocation(FVector(0.0f, 0.0f, 125.0f));
	headMember->Collider->SetWorldScale3D(FVector(0.0f, 0.0f, 0.5f));

	//Battery
	batteryMember = CreateDefaultSubobject<UMember>(TEXT("Battery"));
	batteryMember->SetupAttachment(GetMesh(), "BatterySocket");
	batteryMember->SetRelativeLocation(FVector(-100.0f, 0.0f, 35.0f));
	batteryMember->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	batteryMember->Collider->SetWorldScale3D(FVector(1.0f, 1.0f, 1.03f));

	//Cabine
	cabineMember = CreateDefaultSubobject<UMember>(TEXT("Cabine"));
	cabineMember->SetupAttachment(GetMesh(), "CabineSocket");
	cabineMember->Collider->SetWorldScale3D(FVector(6.5f, 10.0f, 5.5f));

	//Arms
	//Left arm
	leftArmMember = CreateDefaultSubobject<UMember>(TEXT("LeftArm"));
	leftArmMember->SetupAttachment(GetMesh(), "LeftArmSocket");
	leftArmMember->SetRelativeLocation(FVector(16.0f, 90.0f, 140.0f));
	leftArmMember->SetRelativeRotation(FRotator(0.0f, 0.0f, 60.0f));
	leftArmMember->Collider->SetWorldScale3D(FVector(1.0f, 2.0f, 1.5f));

	//Left Forearm	
	leftForearmMember = CreateDefaultSubobject<UMember>(TEXT("LeftForearm"));
	leftForearmMember->SetupAttachment(GetMesh(), "ForearmLeftSocket");
	leftForearmMember->SetRelativeLocation(FVector(140.0f, 90.0f, 140.0f));
	leftForearmMember->SetRelativeRotation(FRotator(0.0f, 0.0f, 100.0f));
	leftForearmMember->Collider->SetWorldScale3D(FVector(1.0f, 2.0f, 1.5f));

	//Right arm
	rightArmMember = CreateDefaultSubobject<UMember>(TEXT("RightArm"));
	rightArmMember->SetupAttachment(GetMesh(), "RightArmSocket");
	rightArmMember->SetRelativeLocation(FVector(16.0f, -90.0f, 140.0f));
	rightArmMember->SetRelativeRotation(FRotator(0.0f, 0.0f, 60.0f));
	rightArmMember->Collider->SetWorldScale3D(FVector(1.0f, 2.0f, 1.5f));

	//Right Forearm	
	rightForearmMember = CreateDefaultSubobject<UMember>(TEXT("RightForearm"));
	rightForearmMember->SetupAttachment(GetMesh(), "ForearmRightSocket");
	rightForearmMember->SetRelativeLocation(FVector(140.0f, -90.0f, 140.0f));
	rightForearmMember->SetRelativeRotation(FRotator(0.0f, 0.0f, 100.0f));
	rightForearmMember->Collider->SetWorldScale3D(FVector(1.0f, 2.0f, 1.5f));
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

void ABaseCharacter::DealDamage(float _amount)
{
	healPoint -= _amount;
	if (healPoint <= 0)
	{		
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


const FVector2D ABaseCharacter::GetHeadLookOffset() const
{
	return headLookOffset;
}

void ABaseCharacter::FirstAttack()
{
	Attack(0);	
}

void ABaseCharacter::SecondAttack()
{
	Attack(1);
}

void ABaseCharacter::Attack(int _weapon)
{
	UWorld* world = GetWorld();

	if (!world) return;

	if (weapons.Num() > 0 && weapons[_weapon] && weapons[_weapon]->projectile)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		TSubclassOf<AActor> ProjectileClass = weapons[_weapon]->projectile;
		float projectileSpread = FMath::Clamp(weapons[_weapon]->spread, 0.0f, 100.0f);
		float projectileShoot = FMath::Clamp(weapons[_weapon]->bulletNumber, 0.0f, 100.0f);

		const float coneHalfAngleRad = FMath::DegreesToRadians(projectileSpread);
		FVector forwardVector = projectileSpawnPoint->GetForwardVector();
        FVector spawnLocation = projectileSpawnPoint->GetComponentLocation();
		FRotator forwardRotator = forwardVector.Rotation();

		for(int i = 0; i < projectileShoot; i++)
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
