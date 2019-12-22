// Copyright Elyctech


#include "Tank/AiTankController.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#include "Tank/Tank.h"


AAiTankController::AAiTankController()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AAiTankController::Tick(
	float DeltaTime
) {
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	ATank* AiTank = Cast<ATank>(
		GetPawn()
	);

	AiTank->AimAt(
		PlayerPawn->GetActorLocation()
	);

	// TODO Implement Firing when not annoying to do so
}
