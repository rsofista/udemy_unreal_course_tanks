// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnyWhere, Category = Setup)
	float MaxDegreesPerSecond = 15;

	UPROPERTY(EditAnyWhere, Category = Setup, meta = (ClampMin = "-30.0", ClampMax = "100.0", UIMin = "-30.0", UIMax = "100.0"))
	float MaxDegreesElevation = 40;

	UPROPERTY(EditAnyWhere, Category = Setup, meta = (ClampMin = "-30.0", ClampMax = "100.0", UIMin = "-30.0", UIMax = "100.0"))
	float MinDegreesElevation = -10;

public:
	void Elevate(const float RelativeSpeed);
};
