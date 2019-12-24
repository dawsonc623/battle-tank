// Copyright Elyctech


#include "Tank/Track.h"


void UTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(
		this,
		&UTrack::OnHit
	);
}

void UTrack::OnHit(
	UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse,
	const FHitResult& Hit
) {
	// Apply forces each time the tracks meet with something

	UPrimitiveComponent* Tank = Cast<UPrimitiveComponent>(
		GetOwner()->GetRootComponent()
	);

	if (ensure(Tank))
	{
		// Driving force

		FVector ForceApplied = GetForwardVector() * CurrentThrottle * MaximumTrackDrivingForce;
		FVector ForceLocation = GetComponentLocation();

		Tank->AddForceAtLocation(
			ForceApplied,
			ForceLocation
		);

		// Sideways force

		FVector TankRightVector = Tank->GetRightVector();

		float SidewaysSpeed = FVector::DotProduct(
			Tank->GetComponentVelocity(),
			TankRightVector
		);

		// Use negative sideways speed to reduce the sideways velocity to zero
		float DeltaTime = GetWorld()->GetDeltaSeconds();

		FVector CounterAcceleration = -SidewaysSpeed / DeltaTime * TankRightVector;

		FVector Friction = (Tank->GetMass() * CounterAcceleration) / 2.0f;

		// Not sure why adding it to the tracks breaks it but not the body

		/*Tank->AddForceAtLocation(
			Friction,
			Tank->GetComponentLocation()
		);*/

		Tank->AddForce(
			Friction
		);

		// Reset Throttle

		CurrentThrottle = 0.0f;
	}
}

void UTrack::SetThrottle(
	float NewThrottle
) {
	CurrentThrottle = FMath::Clamp(CurrentThrottle + NewThrottle, -1.0f, 1.0f);
}
