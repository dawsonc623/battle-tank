// Copyright Elyctech


#include "WarMachine/Projectile.h"

#include "GameFramework/ProjectileMovementComponent.h"


AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;


	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
		FName("ProjectileMovementComponent")
	);

	ProjectileMovementComponent->bAutoActivate = false;
}


void AProjectile::Launch(
	float LaunchSpeed
) {
	ProjectileMovementComponent->SetVelocityInLocalSpace(
		FVector::ForwardVector * LaunchSpeed
	);

	ProjectileMovementComponent->Activate();
}
