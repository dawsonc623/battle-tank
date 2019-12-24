// Copyright Elyctech


#include "WarMachine/WeaponAimingComponent.h"

#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

#include "WarMachine/Barrel.h"
#include "WarMachine/Projectile.h"
#include "WarMachine/Turret.h"


UWeaponAimingComponent::UWeaponAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
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

			if (
				BarrelRotation.Equals(
					LaunchRotation,
					0.1
				)
			) {
				if (AimingState != EAimingState::Reloading && AimingState != EAimingState::Ready)
				{
					AimingState = EAimingState::Ready;
				}
			}
			else
			{
				if (AimingState != EAimingState::Reloading && AimingState != EAimingState::Aiming)
				{
					AimingState = EAimingState::Aiming;
				}

				FRotator DeltaRotation = LaunchRotation - BarrelRotation;

				Barrel->Elevate(
					DeltaRotation.Pitch
				);

				float Rotation = DeltaRotation.Yaw;

				if (Rotation > 180)
				{
					Rotation -= 360;
				}
				else if (Rotation < -180)
				{
					Rotation += 360;
				}

				Turret->Rotate(
					Rotation
				);
			}
		}
	}
}

void UWeaponAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	LastFireTime = GetWorld()->GetTimeSeconds();
}

void UWeaponAimingComponent::FireProjectile()
{
	if (ensure(Barrel && ProjectileBlueprint) && AimingState != EAimingState::Reloading)
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
		AimingState = EAimingState::Reloading;
	}
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

	if (AimingState == EAimingState::Reloading && GetWorld()->GetTimeSeconds() - LastFireTime > ReloadDelay)
	{
		if (AimingState != EAimingState::Ready)
		{
			AimingState = EAimingState::Ready;
		}
	}
}
