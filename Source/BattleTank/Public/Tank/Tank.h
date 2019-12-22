// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"


class UBarrel;


class UWeaponAimingComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:

	ATank();


	void AimAt(
		const FVector& AimLocation
	);

	UFUNCTION(BlueprintCallable, Category = "BarrelConfiguration")
	void SetBarrel(
		UBarrel* NewBarrel
	);


protected:

	virtual void BeginPlay() override;


private:

	UWeaponAimingComponent* AimingComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

};
