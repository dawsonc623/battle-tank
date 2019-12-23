// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"


class AProjectile;
class UBarrel;
class UTankMovementComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:

	ATank();


	UFUNCTION(BlueprintCallable, Category = "Combat")
	void FireProjectile();


protected:

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UTankMovementComponent* MovementComponent = nullptr;


	virtual void BeginPlay() override;


private:


	UBarrel* Barrel = nullptr;

	float LastFireTime = 0.0f;


	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float ReloadDelay = 3.0f;

};
