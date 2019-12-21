// Copyright Elyctech


#include "Tank/AiTankController.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#include "Tank/Tank.h"


void AAiTankController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AI joined"))
	UE_LOG(LogTemp, Warning, TEXT("AI possessed %s"), *(GetPawn()->GetName()))

	ATank* PlayerTank = Cast<ATank>(
		GetWorld()->GetFirstPlayerController()->GetPawn()
	);

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI preparing to target player %s"), *(PlayerTank->GetName()))
	}
}
