// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Projectile.generated.h"


class UProjectileMovementComponent;


UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	

public:	

	AProjectile();


	void Launch(
		float LaunchSpeed
	);


private:

	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

};
