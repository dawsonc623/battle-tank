// Copyright Elyctech


#include "Tank/AiTankController.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#include "WarMachine/WeaponAimingComponent.h"


void AAiTankController::Tick(
	float DeltaTime
) {
	Super::Tick(
		DeltaTime
	);

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	APawn* AiPawn = GetPawn();

	if (ensure(PlayerPawn && AiPawn))
	{
		MoveToActor(
			PlayerPawn,
			FiringRadius
		);

		UWeaponAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UWeaponAimingComponent>();

		if (ensure(AimingComponent))
		{
			AimingComponent->AimAt(
				PlayerPawn->GetActorLocation()
			);

			if (AimingComponent->GetAimingState() == EAimingState::Ready)
			{
				// TODO Re-enable firing when it is not frustrating to have it on
				// AimingComponent->FireProjectile();
			}
		}
	}
}
