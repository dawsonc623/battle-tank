// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "AiTankController.generated.h"


// TODO This should have gone in an Ai directory =/

UCLASS()
class BATTLETANK_API AAiTankController : public AAIController
{
	GENERATED_BODY()


public:

	virtual void Tick(
		float DeltaTime
	) override;


private:

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FiringRadius = 8000;

};
