// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

#include "Tank.h"
#include "TankPlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	this->ControlledTank = Cast<ATank>(this->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector PlayerLocation = this->GetTargetTank()->GetActorLocation();

	this->ControlledTank->AimAt(&PlayerLocation);
	this->ControlledTank->Fire();
}

ATank* ATankAIController::GetTargetTank() const
{
	return Cast<ATankPlayerController>(this->GetWorld()->GetFirstPlayerController())->GetControlledTank();
}
