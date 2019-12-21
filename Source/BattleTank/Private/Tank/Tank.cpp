// Copyright Elyctech


#include "Tank/Tank.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}


void ATank::AimAt(
	const FVector& AimLocation
) {
	UE_LOG(LogTemp, Warning, TEXT("Aiming toward location %s"), *(AimLocation.ToString()))
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Tank %s spawned"), *GetName())
}
