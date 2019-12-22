// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"

#include "Barrel.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:

	UBarrel();


	void Elevate(
		// Rate between -1 and 1
		float ElevationChange
	);


private:

	UPROPERTY(EditDefaultsOnly, Category = "BarrelConfiguration")
	float MaximumElevationRate = 10;

	UPROPERTY(EditDefaultsOnly, Category = "BarrelConfiguration")
	float MaximumElevation = 40;

	UPROPERTY(EditDefaultsOnly, Category = "BarrelConfiguration")
	float MinimumElevation = 0;

};
