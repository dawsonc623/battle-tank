// Copyright Elyctech


#include "Tank/Tank.h"

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
	UE_LOG(LogTemp, Warning, TEXT("PEW PEW"))
}

void ATank::SetBarrel(
	UBarrel* NewBarrel
) {
	AimingComponent->SetBarrel(
		NewBarrel
	);
}

void ATank::SetTurret(
	UTurret* NewTurret
) {
	AimingComponent->SetTurret(
		NewTurret
	);
}
