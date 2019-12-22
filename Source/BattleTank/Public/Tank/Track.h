// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"

#include "Track.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:

	UTrack();


	UFUNCTION(BlueprintCallable, Category = "Driving")
	void SetThrottle(
		float NewThrottle
	);

private:

	UPROPERTY(EditDefaultsOnly, Category = "Driving")
	float MaximumTrackDrivingForce = 40000000;

};
