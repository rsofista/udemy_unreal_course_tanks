// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Math.h"
//
#include "TankTrack.h"

void UTankMovementComponent::SetTankTracks(UTankTrack* LeftTrack, UTankTrack* RightTrack)
{
	this->RightTrack = RightTrack;
	this->LeftTrack = LeftTrack;
}

void UTankMovementComponent::MoveFoward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	Throw = FMath::Clamp<float>(Throw, -1, +1);

	this->LeftTrack->ApplyThrottle(Throw);
	this->RightTrack->ApplyThrottle(Throw);
}

void UTankMovementComponent::MoveRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	Throw = FMath::Clamp<float>(Throw, -1, +1);

	this->LeftTrack->ApplyThrottle(Throw);
	this->RightTrack->ApplyThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveVelocity %s"), *MoveVelocity.GetSafeNormal().ToString());

	auto AIIntendedDirection = MoveVelocity.GetSafeNormal();
	auto TankDirection = this->GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto FowardThouw = FVector::DotProduct(AIIntendedDirection, TankDirection);
	auto RightThouw = FVector::CrossProduct(TankDirection, AIIntendedDirection).Z;

	//this->MoveFoward(FowardThouw);
	this->MoveRight(RightThouw);
}
