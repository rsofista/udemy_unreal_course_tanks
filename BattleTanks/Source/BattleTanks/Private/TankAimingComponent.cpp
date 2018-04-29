// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Vector.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrel(UTankBarrel* Barrel)
{
	this->Barrel = Barrel;
}

void UTankAimingComponent::AimAt(const FVector * HitLocation, const float LauchSpeed)
{
	FVector BarrelTipLocation = this->Barrel->GetSocketLocation(FName("Tip"));
	FVector LauchVelocity;

	if (
		UGameplayStatics::SuggestProjectileVelocity(
			this,
			LauchVelocity,
			BarrelTipLocation,
			*HitLocation,
			LauchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
	) {
		UE_LOG(LogTemp, Warning, TEXT("%f: Here: %s"), this->GetWorld()->GetTimeSeconds(), *LauchVelocity.GetSafeNormal().ToString());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%f: NOPE"), this->GetWorld()->GetTimeSeconds());
	}

	const FRotator BarrelRotator = this->Barrel->GetForwardVector().Rotation();
	const FRotator AimRotator = LauchVelocity.GetSafeNormal().Rotation();
	const FRotator DeltaRotator = AimRotator - BarrelRotator;	

	this->Barrel->Elevate(DeltaRotator.Pitch);
}
