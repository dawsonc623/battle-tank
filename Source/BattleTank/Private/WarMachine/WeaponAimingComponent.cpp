// Copyright Elyctech


#include "WarMachine/WeaponAimingComponent.h"


UWeaponAimingComponent::UWeaponAimingComponent()
{
	// TODO Should this tick?
	PrimaryComponentTick.bCanEverTick = true;
}


void UWeaponAimingComponent::AimAt(
	const FVector& AimLocation
) {
	UE_LOG(LogTemp, Warning, TEXT("Aiming toward location %s"), *(AimLocation.ToString()))
}

void UWeaponAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UWeaponAimingComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction
) {
	Super::TickComponent(
		DeltaTime,
		TickType,
		ThisTickFunction
	);
}

