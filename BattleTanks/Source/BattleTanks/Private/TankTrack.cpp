// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Components/PrimitiveComponent.h"

void UTankTrack::ApplyThrottle(const float Throttle)
{
	auto ForceApplied = this->GetForwardVector() * Throttle * this->MaxDrivingForce;
	auto ForceLocation = this->GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(this->GetOwner()->GetRootComponent());

	if (TankRoot) {
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Le throttle %f"), Throttle)
	}
}
