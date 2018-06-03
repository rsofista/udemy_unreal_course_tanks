// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
//
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

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
	this->Barrel = Barrel;
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
	if (this->ProjectileClass == nullptr) { return; }

	UWorld* World = GetWorld();

	if (World->GetTimeSeconds() - this->LastTimeFired > this->ReloadTimeInSeconds) {
		AProjectile* Projectile = World->SpawnActor<AProjectile>(
			this->ProjectileClass,
			this->Barrel->GetSocketLocation(FName("BarrelTipSocket")),
			this->Barrel->GetSocketRotation(FName("BarrelTipSocket"))
		);

		Projectile->Launch(this->LaunchSpeed);

		this->LastTimeFired = World->GetTimeSeconds();
	}
}
