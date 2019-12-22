// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"

#include "TankMovementComponent.generated.h"


class UTrack;


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()


public:

	UTankMovementComponent();


	virtual void RequestDirectMove(
		const FVector& MoveVelocity,
		bool bForceMaxSpeed
	) override;


	UFUNCTION(BlueprintCallable, Category = "TrackConfiguration")
	void Initialize(
		UTrack* NewLeftTrack,
		UTrack* NewRightTrack
	);

	// Rate is a value between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveStraight(
		float Rate
	);

	// Rate is a value between -1 and +1, where -1 is counterclockwise and +1 is clockwise
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void Turn(
		float Rate
	);


private:

	UTrack* LeftTrack = nullptr;

	UTrack* RightTrack = nullptr;

};
