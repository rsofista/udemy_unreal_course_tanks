// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnyWhere, Category = Setup)
	float MaxDegreesPerSecond = 15;
public:
	void Rotate(const float RelativeSpeed);
};
