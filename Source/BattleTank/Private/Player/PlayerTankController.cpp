// Copyright Elyctech


#include "Player/PlayerTankController.h"

#include "Engine/World.h"
#include "GameFramework/Pawn.h"

#include "Tank/Tank.h"
#include "WarMachine/WeaponAimingComponent.h"


void APlayerTankController::BeginPlay()
{
	Super::BeginPlay();

	// TODO Inject AimingComponent instead of this
	UWeaponAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UWeaponAimingComponent>();

	if (ensure(AimingComponent))
	{
		AimingComponentReady(
			AimingComponent
		);
	}
}

void APlayerTankController::Tick(
	float DeltaTime
) {
	Super::Tick(
		DeltaTime
	);

	// Get the viewport size

	int32 ViewportSizeX;
	int32 ViewportSizeY;

	GetViewportSize(
		ViewportSizeX,
		ViewportSizeY
	);

	// Get where the aim indicator is aiming

	FVector2D AimIndicatorScreenPosition(
		ViewportSizeX * AimIndicatorX,
		ViewportSizeY * AimIndicatorY
	);

	FHitResult AimHitResult;

	bool bHitLocationFound = GetHitResultAtScreenPosition(
		AimIndicatorScreenPosition,
		ECollisionChannel::ECC_WorldStatic,
		false,
		AimHitResult
	);

	// If we are aiming at something, move the barrel towards it

	if (bHitLocationFound)
	{
		// TODO Inject AimingComponent instead of this
		UWeaponAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UWeaponAimingComponent>();

		if (ensure(AimingComponent))
		{
			AimingComponent->AimAt(
				AimHitResult.ImpactPoint
			);
		}
	}
}
