// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

#include "Engine/World.h"
#include "Math.h"

void UTankBarrel::Elevate(const float RelativeSpeed)
{
	const float ElevationChange = FMath::Clamp<float>(RelativeSpeed, -1, +1) * this->MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	const float NewElevation = FMath::Clamp<float>(this->RelativeRotation.Pitch + ElevationChange, this->MinDegreesElevation, this->MaxDegreesElevation);

	this->SetRelativeRotation(FRotator(NewElevation, 0, 0));
}
