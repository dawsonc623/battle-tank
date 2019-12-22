// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"


class AProjectile;
class UBarrel;
class UTankMovementComponent;
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

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void FireProjectile();

	UFUNCTION(BlueprintCallable, Category = "BarrelConfiguration")
	void SetBarrel(
		UBarrel* NewBarrel
	);

	UFUNCTION(BlueprintCallable, Category = "TurretConfiguration")
	void SetTurret(
		UTurret* NewTurret
	);


protected:

	virtual void BeginPlay() override;


	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UTankMovementComponent* MovementComponent = nullptr;


private:

	UWeaponAimingComponent* AimingComponent = nullptr;

	UBarrel* Barrel = nullptr;

	float LastFireTime = 0.0f;


	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectileConfiguration")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadDelay = 3.0f;

};
