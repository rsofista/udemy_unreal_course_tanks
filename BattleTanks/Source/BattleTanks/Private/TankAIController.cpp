// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ai tank => %s"), *this->GetControlledTank()->GetName());
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}
