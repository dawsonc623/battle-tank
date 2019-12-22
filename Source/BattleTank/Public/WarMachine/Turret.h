// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"

#include "Turret.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:

	UTurret();


	void Rotate(
		float RotationChange
	);


private:

	UPROPERTY(EditDefaultsOnly, Category = "TurretConfiguration")
	float MaximumRotationRate = 10;

};
