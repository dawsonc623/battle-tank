// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "PlayerTankController.generated.h"


UCLASS()
class BATTLETANK_API APlayerTankController : public APlayerController
{
	GENERATED_BODY()
	

protected:

	virtual void BeginPlay() override;

};
