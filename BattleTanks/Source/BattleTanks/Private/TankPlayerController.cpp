// Fill out your copyright notice in the Description page of Project Settings.

#define OUT

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("playa tank => %s"), *this->GetControlledTank()->GetName());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->AimAtCrossHair();
}

void ATankPlayerController::AimAtCrossHair()
{
	UE_LOG(LogTemp, Warning, TEXT("Aiming and shit"));

	FVector HitLocation;

	if (this->GetSightRayHitLocation(OUT &HitLocation)) {

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector * OutHitLocation) const
{
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}
