// Copyright Elyctech


#include "Tank/AiTankController.h"


void AAiTankController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AI joined"));
}
