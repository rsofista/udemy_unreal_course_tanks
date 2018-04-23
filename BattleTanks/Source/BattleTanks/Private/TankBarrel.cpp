// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(const float RelativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("DegreesPerSecond(%f)"), RelativeSpeed);
}
