// Copyright Elyctech


#include "Player/PlayerTankController.h"

#include "GameFramework/Pawn.h"


void APlayerTankController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Player joined"))
	UE_LOG(LogTemp, Warning, TEXT("Player possessed %s"), *(GetPawn()->GetName()))
}
