// Copyright Elyctech


#include "WarMachine/WeaponAimingComponent.h"

#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

#include "WarMachine/Barrel.h"
#include "WarMachine/Turret.h"


UWeaponAimingComponent::UWeaponAimingComponent()
{
	// TODO Should this tick?
	PrimaryComponentTick.bCanEverTick = false;
}


void UWeaponAimingComponent::AimAt(
	const FVector& AimLocation
) {
	if (ensure(Barrel && Turret))
	{
		FVector LaunchVelocity;

		FVector FiringLocation = Barrel->GetSocketLocation(
			FName("Projectile")
		);

		bool bVelocityCalculated = UGameplayStatics::SuggestProjectileVelocity(
			this,
			LaunchVelocity,
			FiringLocation,
			AimLocation,
			LaunchSpeed,
			false,
			0.0f,
			0.0f,
			ESuggestProjVelocityTraceOption::DoNotTrace
		);

		if (bVelocityCalculated)
		{
			FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
			FRotator LaunchRotation = LaunchVelocity.Rotation();

			FRotator DeltaRotation = LaunchRotation - BarrelRotation;

			Barrel->Elevate(
				DeltaRotation.Pitch
			);

			Turret->Rotate(
				DeltaRotation.Yaw
			);
		}
	}
}

void UWeaponAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UWeaponAimingComponent::Initialize(
	UBarrel* NewBarrel,
	UTurret* NewTurret
) {
	Barrel = NewBarrel;
	Turret = NewTurret;
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
