// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankTurret;
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

public:	
	void SetBarrel(UTankBarrel* Barrel);
	void SetTurret(UTankTurret* Turret);
	// Aims the Barrel to a location, elevating and rotating as necessary
	// The LaunchSpeed is used to know how to calculate de angle
	void AimAt(const FVector* HitLocation, const float LauchSpeed);
};
