// Copyright Elyctech


#include "Tank/Tank.h"

#include "Engine/World.h"

#include "WarMachine/Barrel.h"
#include "WarMachine/Projectile.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}


void ATank::BeginPlay()
{
	Super::BeginPlay();

	LastFireTime = GetWorld()->GetDeltaSeconds();
}

void ATank::FireProjectile()
{
	if (ensure(Barrel && ProjectileBlueprint) && (GetWorld()->GetTimeSeconds() - LastFireTime) >= ReloadDelay)// && AimingState != EAimingState::Reloading)
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

		LastFireTime = GetWorld()->GetTimeSeconds();
		//AimingState = EAimingState::Reloading;
	}
}
