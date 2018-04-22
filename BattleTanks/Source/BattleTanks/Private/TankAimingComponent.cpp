// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Vector.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::SetBarrel(UStaticMeshComponent* Barrel)
{
	this->Barrel = Barrel;
}

void UTankAimingComponent::AimAt(const FVector * HitLocation, const float LauchSpeed)
{
	FVector BarrelTipLocation = this->Barrel->GetSocketLocation(FName("Tip"));
	FVector LauchVelocity;
	const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam;
	const TArray<AActor*> ActorsToIgnore = TArray<AActor*>();

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
			ESuggestProjVelocityTraceOption::DoNotTrace,
			ResponseParam,
			ActorsToIgnore,
			true
		)
	) {
		UE_LOG(LogTemp, Warning, TEXT("Here: %s"), *LauchVelocity.GetSafeNormal().ToString());
	}
}
