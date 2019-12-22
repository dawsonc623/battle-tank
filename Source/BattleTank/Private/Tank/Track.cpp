// Copyright Elyctech


#include "Tank/Track.h"


UTrack::UTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UTrack::SetThrottle(
	float NewThrottle
) {
	FVector ForceApplied = GetForwardVector() * NewThrottle * MaximumTrackDrivingForce;
	FVector ForceLocation = GetComponentLocation();

	UPrimitiveComponent* Tank = Cast<UPrimitiveComponent>(
		GetOwner()->GetRootComponent()
	);

	Tank->AddForceAtLocation(
		ForceApplied,
		ForceLocation
	);
}
