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
		AimLocation
	);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Tank %s spawned"), *GetName())
}
