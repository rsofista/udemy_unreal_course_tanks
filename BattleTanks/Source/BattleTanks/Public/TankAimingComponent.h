// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UTankBarrel* Barrel = nullptr;
public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

public:	
	void SetBarrel(UTankBarrel* Barrel);

	void AimAt(const FVector* HitLocation, const float LauchSpeed);
};
