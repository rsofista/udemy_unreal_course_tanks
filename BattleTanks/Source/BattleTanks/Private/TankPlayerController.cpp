// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

#include "Tank.h"

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

	if (this->GetSightRayHitLocation(&HitLocation)) {
		
	};

	this->GetControlledTank()->AimAt(&HitLocation);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector* OutHitLocation) const
{
	int32 ViewportX, ViewportY;

	this->GetViewportSize(ViewportX, ViewportY);

	FVector2D ScreenLocation = FVector2D(
		ViewportX * this->CrosshairPosition.X,
		ViewportY * this->CrosshairPosition.Y
	);

	FVector WorldLocation, LookDirection;
	
	if (this->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection)) {
		FHitResult Hit;
		const FVector VectorStart = this->PlayerCameraManager->GetCameraLocation();
		const FVector VectorEnd = VectorStart + (LookDirection * this->LineTraceReach);

		if (
			GetWorld()->LineTraceSingleByChannel(
				Hit, 
				VectorStart, 
				VectorEnd,
				ECollisionChannel::ECC_Visibility
			)
		) {
			OutHitLocation->X = Hit.Location.X;
			OutHitLocation->Y = Hit.Location.Y;
			OutHitLocation->Z = Hit.Location.Z;

			return true;
		}
		else {
			OutHitLocation->X = VectorEnd.X;
			OutHitLocation->Y = VectorEnd.Y;
			OutHitLocation->Z = VectorEnd.Z;

			return false;
		}
	}
	
	OutHitLocation->X = ScreenLocation.X;
	OutHitLocation->Y = ScreenLocation.Y;
	OutHitLocation->Z = 0;

	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}
