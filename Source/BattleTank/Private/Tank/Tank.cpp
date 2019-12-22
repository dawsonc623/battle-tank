// Copyright Elyctech


#include "Tank/Tank.h"

#include "Engine/World.h"

#include "WarMachine/Barrel.h"
#include "WarMachine/Projectile.h"
#include "WarMachine/WeaponAimingComponent.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

	AimingComponent = CreateDefaultSubobject<UWeaponAimingComponent>(
		FName("AimingComponent")
	);
}


void ATank::AimAt(
	const FVector& AimLocation
) {
	AimingComponent->AimAt(
		AimLocation,
		LaunchSpeed
	);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::FireProjectile()
{
	if (ensure(Barrel && ProjectileBlueprint))// && AimingState != EAimingState::Reloading)
	{
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(
				FName(
					"Projectile"
				)
			),
			Barrel->GetSocketRotation(
				FName(
					"Projectile"
				)
			)
		);

		Projectile->Launch(
			LaunchSpeed
		);

		//LastFireTime = GetWorld()->GetTimeSeconds();
		//AimingState = EAimingState::Reloading;
	}
}

void ATank::SetBarrel(
	UBarrel* NewBarrel
) {
	AimingComponent->SetBarrel(
		NewBarrel
	);

	Barrel = NewBarrel;
}

void ATank::SetTurret(
	UTurret* NewTurret
) {
	AimingComponent->SetTurret(
		NewTurret
	);
}
