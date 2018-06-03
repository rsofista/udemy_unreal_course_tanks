// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("IntendMoveFoward(%f)"), Throw);
}

void UTankMovementComponent::IntendMoveBackwards(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("IntendMoveBackwards(%f)"), Throw);
}
