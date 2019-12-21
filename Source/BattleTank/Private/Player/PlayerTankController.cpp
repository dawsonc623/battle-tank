// Copyright Elyctech


#include "Player/PlayerTankController.h"


void APlayerTankController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Player joined"));
}
