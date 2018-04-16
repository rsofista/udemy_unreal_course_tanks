// Fill out your copyright notice in the Description page of Project Settings.

#define OUT

#include "TankPlayerController.h"

#include "Math/Vector.h"
#include "Engine/World.h"

void ATankPlayerController::BeginPlay()
{	
	Super::BeginPlay();

	this->CrosshairPosition.X = 0.5;
	this->CrosshairPosition.Y = 0.3333;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->AimAtCrossHair();
}

void ATankPlayerController::AimAtCrossHair()
{
	FVector HitLocation;

	if (this->GetSightRayHitLocation(OUT &HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HIT %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector* OutHitLocation) const
{
	int32 ViewportX, ViewportY;

	this->GetViewportSize(OUT ViewportX, OUT ViewportY);

	FVector2D ScreenLocation = FVector2D(
		ViewportX * this->CrosshairPosition.X,
		ViewportY * this->CrosshairPosition.Y
	);

	FVector WorldLocation, LookDirection;

	if (this->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT WorldLocation, OUT LookDirection)) {
		FHitResult Hit;
		const FVector VectorStart = this->PlayerCameraManager->GetCameraLocation();
		const FVector VectorEnd = VectorStart + (LookDirection * this->LineTraceReach);

		if (
			GetWorld()->LineTraceSingleByChannel(
				OUT Hit, 
				VectorStart, 
				VectorEnd,
				ECollisionChannel::ECC_Visibility
			)
		) {
			OutHitLocation->X = Hit.Location.X;
			OutHitLocation->Y = Hit.Location.Y;
			OutHitLocation->Z = Hit.Location.Z;

			UE_LOG(LogTemp, Warning, TEXT("ACTOR %s"), *Hit.GetActor()->GetName());

			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}
