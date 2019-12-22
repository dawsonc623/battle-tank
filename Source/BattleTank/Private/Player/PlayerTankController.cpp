// Copyright Elyctech


#include "Player/PlayerTankController.h"

#include "Engine/World.h"
#include "GameFramework/Pawn.h"

#include "Tank/Tank.h"


APlayerTankController::APlayerTankController()
{
	PrimaryActorTick.bCanEverTick = true;
}


void APlayerTankController::BeginPlay()
{
	Super::BeginPlay();
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
		ATank* PlayerTank = Cast<ATank>(GetPawn());

		PlayerTank->AimAt(
			AimHitResult.ImpactPoint
		);
	}
}
