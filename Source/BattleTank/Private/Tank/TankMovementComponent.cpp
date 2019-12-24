// Copyright Elyctech


#include "Tank/TankMovementComponent.h"

#include "Tank/Track.h"


UTankMovementComponent::UTankMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UTankMovementComponent::Initialize(
	UTrack* NewLeftTrack,
	UTrack* NewRightTrack
) {
	LeftTrack = NewLeftTrack;
	RightTrack = NewRightTrack;
}

void UTankMovementComponent::MoveStraight(
	float Rate
) {
	if (ensure(LeftTrack && RightTrack))
	{
		LeftTrack->SetThrottle(
			Rate
		);

		RightTrack->SetThrottle(
			Rate
		);
	}
}

void UTankMovementComponent::RequestDirectMove(
	const FVector& MoveVelocity,
	bool bForceMaxSpeed
) {
	FVector TankForwardVector = GetOwner()->GetActorForwardVector();
	FVector AiMovementVector = MoveVelocity.GetSafeNormal();

	float StraightRate = FVector::DotProduct(
		TankForwardVector,
		AiMovementVector
	);

	float TurnRate = FVector::CrossProduct(
		TankForwardVector,
		AiMovementVector
	).Z;

	MoveStraight(
		StraightRate
	);

	Turn(
		TurnRate
	);
}

void UTankMovementComponent::Turn(
	float Rate
) {
	if (ensure(LeftTrack && RightTrack))
	{
		LeftTrack->SetThrottle(
			Rate
		);

		RightTrack->SetThrottle(
			-Rate
		);
	}
}
