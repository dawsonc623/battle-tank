// Copyright Elyctech


#include "Tank/Tank.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}


void ATank::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Tank %s spawned"), *GetName())
}
