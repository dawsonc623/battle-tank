// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "WeaponAimingComponent.generated.h"


class UBarrel;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UWeaponAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	

	UWeaponAimingComponent();


	void AimAt(
		const FVector& AimLocation,
		float LaunchSpeed
	);

	void SetBarrel(
		UBarrel* NewBarrel
	);

	virtual void TickComponent(
		float DeltaTime,
		ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;


protected:

	UBarrel* Barrel = nullptr;

	virtual void BeginPlay() override;
		
};
