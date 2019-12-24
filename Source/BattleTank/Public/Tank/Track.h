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

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetThrottle(
		float NewThrottle
	);

protected:

	virtual void BeginPlay() override;


private:

	float CurrentThrottle = 0.0f;


	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float MaximumTrackDrivingForce = 40000000;


	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		FVector NormalImpulse,
		const FHitResult& Hit
	);

};
