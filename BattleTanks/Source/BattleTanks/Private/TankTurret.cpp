// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

#include "Engine/World.h"
#include "Math.h"

void UTankTurret::Rotate(const float RelativeSpeed)
{
	const float RotationChange = FMath::Clamp<float>(RelativeSpeed, -1, +1) * this->MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	const float NewRotation = this->RelativeRotation.Yaw + RotationChange;	

	this->SetRelativeRotation(FRotator(0, NewRotation, 0));
}
