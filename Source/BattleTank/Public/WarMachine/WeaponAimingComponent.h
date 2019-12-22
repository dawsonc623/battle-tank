// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "WeaponAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UWeaponAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	

	UWeaponAimingComponent();


	void AimAt(
		const FVector& AimLocation
	);

	virtual void TickComponent(
		float DeltaTime,
		ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;


protected:

	virtual void BeginPlay() override;
		
};
