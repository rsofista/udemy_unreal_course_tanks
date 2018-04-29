// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankTurret;
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;
class UProjectileMovementComponent;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UTankAimingComponent* TankAimingComponent = nullptr;
public:
	// Sets default values for this pawn's properties
	ATank();
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UTankBarrel* Barrel);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurret(UTankTurret* Turret);

	void AimAt(const FVector* HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 5000; // m/s

	UPROPERTY(EditAnywhere, Category = Firing)
	float ReloadTimeInSeconds = 3;

	float LastTimeFired = -100;
};
