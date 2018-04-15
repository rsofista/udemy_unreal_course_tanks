// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

public:
	ATank* GetControlledTank() const;
};
