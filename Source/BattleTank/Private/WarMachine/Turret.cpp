// Copyright Elyctech


#include "WarMachine/Turret.h"


UTurret::UTurret()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UTurret::Rotate(
	// Rate between -1 and 1
	float RotationChange
) {
	RotationChange = FMath::Clamp(
		RotationChange,
		-1.0f, 1.0f
	);

	float RotationDelta = MaximumRotationRate * RotationChange * GetWorld()->GetDeltaSeconds();

	SetRelativeRotation(
		FRotator(
			0.0f,
			RelativeRotation.Yaw + RotationDelta,
			0.0f
		)
	);
}
