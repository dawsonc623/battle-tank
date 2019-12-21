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
}

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
