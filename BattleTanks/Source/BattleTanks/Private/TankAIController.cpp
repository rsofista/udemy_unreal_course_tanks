// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

#include "TankPlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ai tank => %s"), *this->GetControlledTank()->GetName());

	ATank* PlayerTank = this->GetPlayerTank();

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("PLAYER TANK FOUND => %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PLAYER TANK NOT FOUND"));
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATankPlayerController>(this->GetWorld()->GetFirstPlayerController())->GetControlledTank();
	/*
	ATankPlayerController* PlayerController = Cast<ATankPlayerController>(this->GetWorld()->GetFirstPlayerController());

	if (PlayerController != nullptr) {
		return PlayerController->GetControlledTank();
	}
	else {
		return nullptr;
	}
	*/
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}
