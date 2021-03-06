// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;	

public:
	virtual void Tick(float DeltaTime) override;

/*---*/
protected:
	UPROPERTY(EditAnywhere)
	FVector2D CrosshairPosition;

	UPROPERTY(EditAnywhere)
	float LineTraceReach = 10 * 1000 * 10;

private:
	void AimAtCrossHair();

	bool GetSightRayHitLocation(FVector *OutHitLocation) const;
public:	
	ATank* GetControlledTank() const;
};
