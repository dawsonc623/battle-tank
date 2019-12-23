// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "PlayerTankController.generated.h"


UCLASS()
class BATTLETANK_API APlayerTankController : public APlayerController
{
	GENERATED_BODY()


public:

	virtual void Tick(
		float DeltaTime
	) override;


protected:

	virtual void BeginPlay() override;


	UFUNCTION(BlueprintImplementableEvent, Category = "AimingComponent")
	void AimingComponentReady(
		UWeaponAimingComponent* AimingComponent
	);


private:

	UPROPERTY(EditDefaultsOnly, Category = "AimIndicator")
	float AimIndicatorX = 0.5;

	UPROPERTY(EditDefaultsOnly, Category = "AimIndicator")
	float AimIndicatorY = 0.333333;

};
