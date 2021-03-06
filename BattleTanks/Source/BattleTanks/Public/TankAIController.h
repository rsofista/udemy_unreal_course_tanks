// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:	
	void Tick(float DeltaTime) override;

protected:
	void BeginPlay() override;

private:
	ATank* GetTargetTank() const;

	ATank* ControlledTank = nullptr;
};
