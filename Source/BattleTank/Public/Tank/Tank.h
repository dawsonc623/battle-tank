// Copyright Elyctech

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:

	ATank();


protected:

	virtual void BeginPlay() override;

};
