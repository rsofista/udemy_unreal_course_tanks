// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("playa tank => %s"), *this->GetControlledTank()->GetName());
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}
