// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "AiTankController.generated.h"


UCLASS()
class BATTLETANK_API AAiTankController : public AAIController
{
	GENERATED_BODY()


public:

	AAiTankController();


	virtual void Tick(
		float DeltaTime
	) override;


private:

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float FiringRadius = 3000;

};
