// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"

// Flag to mark OUT parameters.
#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Door = GetOwner();

	// Check for unset properties
	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("PressurePlate not set on %s."), *Door->GetName());
	}
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() const
{
	float TotalMass = 0.f;

	// Skip this if PressurePlate is not set.
	if (!PressurePlate) { return TotalMass; }

	/// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	///Iterate through them adding their masses.
	for (const auto* OverlappingActor : OverlappingActors)
	{
		auto PrimitiveComponent = OverlappingActor->FindComponentByClass<UPrimitiveComponent>();
		if (PrimitiveComponent) {
			TotalMass += PrimitiveComponent->GetMass();
		}
	}
	
	return TotalMass;
}

