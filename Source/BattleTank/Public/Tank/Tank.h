// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"


class AProjectile;
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


private:

	UWeaponAimingComponent* AimingComponent = nullptr;

	UBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectileConfiguration")
	TSubclassOf<AProjectile> ProjectileBlueprint;

};
