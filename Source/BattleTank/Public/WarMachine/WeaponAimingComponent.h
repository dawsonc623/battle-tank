// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "WeaponAimingComponent.generated.h"


class AProjectile;
class UBarrel;
class UTurret;


UENUM()
enum class EAimingState : uint8
{
	Aiming,
	Ready,
	Reloading
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UWeaponAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	

	UWeaponAimingComponent();


	void AimAt(
		const FVector& AimLocation
	);

	EAimingState GetAimingState() const;

	virtual void TickComponent(
		float DeltaTime,
		ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;


	UFUNCTION(BlueprintCallable, Category = "Combat")
	void FireProjectile();

	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void Initialize(
		UBarrel* NewBarrel,
		UTurret* NewTurret
	);


protected:

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	EAimingState AimingState = EAimingState::Reloading;


	virtual void BeginPlay() override;


private:

	UBarrel* Barrel = nullptr;

	float LastFireTime = 0.0f;

	UTurret* Turret = nullptr;


	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float ReloadDelay = 3.0f;
		
};
