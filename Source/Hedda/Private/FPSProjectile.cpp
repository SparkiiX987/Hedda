#include "FPSProjectile.h"
#include "BaseCharacter.h"


// Sets default values
AFPSProjectile::AFPSProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}

	if (!sphereComponent)
	{
		// Use a sphere as a simple collision representation.
		sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		// Set the sphere's collision profile name to "Projectile".
		sphereComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
		// Set the sphere's collision radius.
		sphereComponent->InitSphereRadius(15.0f);
		// Set the root component to be the collision component.
		RootComponent = sphereComponent;
	}

	if (!projectileMovementComponent)
	{
		// Use this component to drive this projectile's movement.
		projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
			TEXT("ProjectileMovementComponent"));
		projectileMovementComponent->SetUpdatedComponent(sphereComponent);
		projectileMovementComponent->InitialSpeed = 3000.0f;
		projectileMovementComponent->MaxSpeed = 3000.0f;
		projectileMovementComponent->bRotationFollowsVelocity = true;
		projectileMovementComponent->bShouldBounce = true;
		projectileMovementComponent->Bounciness = 0.3f;
		projectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	if (!projectileMesh)
	{
		projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("'/Game/Projectiles/Meshs/Sphere.Sphere'"));
		if (Mesh.Succeeded())
		{
			projectileMesh->SetStaticMesh(Mesh.Object);
		}

		projectileMesh->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
		projectileMesh->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	sphereComponent->SetRelativeScale3D(GetActorRelativeScale3D() * size);
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPSProjectile::OnProjectileHit(AActor* _otherActor, UPrimitiveComponent* _otherComponent)
{
	if (!IsValid(_otherActor) || !IsValid(_otherComponent)) return;

	ABaseCharacter* enemy = Cast<ABaseCharacter>(_otherActor);
	if (IsValid(enemy))
	{
		enemy->DealDamage(damage);s
	}
}
