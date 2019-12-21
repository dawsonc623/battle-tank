// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "AiTankController.generated.h"


UCLASS()
class BATTLETANK_API AAiTankController : public AAIController
{
	GENERATED_BODY()


protected:

	virtual void BeginPlay() override;
	
};
