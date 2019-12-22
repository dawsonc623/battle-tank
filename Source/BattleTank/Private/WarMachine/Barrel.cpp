// Copyright Elyctech


#include "WarMachine/Barrel.h"


UBarrel::UBarrel()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UBarrel::Elevate(
	// Rate between -1 and 1
	float ElevationChange
) {
	ElevationChange = FMath::Clamp(ElevationChange, -1.0f, 1.0f);

	float ElevationDelta = MaximumElevationRate * ElevationChange * GetWorld()->GetDeltaSeconds();

	float NewPitch = FMath::Clamp(
		RelativeRotation.Pitch + ElevationDelta,
		MinimumElevation,
		MaximumElevation
	);

	SetRelativeRotation(FRotator(NewPitch, 0.0f, 0.0f));
}
