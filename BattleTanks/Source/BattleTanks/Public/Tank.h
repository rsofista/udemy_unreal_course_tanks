// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

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
	void SetBarrel(UStaticMeshComponent* Barrel);

	void AimAt(const FVector* HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
