// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	this->PrimaryActorTick.bCanEverTick = false;

	this->TankAimingComponent = CreateAbstractDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::SetBarrel(UTankBarrel* Barrel)
{
	this->TankAimingComponent->SetBarrel(Barrel);
}

void ATank::SetTurret(UTankTurret* Turret)
{
	this->TankAimingComponent->SetTurret(Turret);
}

void ATank::AimAt(const FVector* HitLocation)
{
	this->TankAimingComponent->AimAt(HitLocation, this->LaunchSpeed);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire in the hole"));
}
