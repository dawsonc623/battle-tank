// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"


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


protected:

	virtual void BeginPlay() override;


private:

	UWeaponAimingComponent* AimingComponent = nullptr;

};
