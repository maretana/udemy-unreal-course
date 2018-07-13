// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead of the player can it reach in cm
	float Reach = 150.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* Input = nullptr;

	// Ray-cast and grab what's in reach
	void Grab();

	// Let go of the object grabbed by Grab
	void Release();

	// Find (assumed) attached physics handle.
	void FindPhysicsHandleComponent();

	// Find (assumed) attached input component
	void SetupInputComponent();
	
	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;

	FTwoVectors GetLineTracePoints() const;
};
