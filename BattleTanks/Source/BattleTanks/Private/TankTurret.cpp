// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

#include "Engine/World.h"
#include "Math.h"

void UTankTurret::Rotate(const float NewYaw)
{
	this->SetRelativeRotation(FRotator(this->RelativeRotation.Pitch, NewYaw, this->RelativeRotation.Roll));
}
