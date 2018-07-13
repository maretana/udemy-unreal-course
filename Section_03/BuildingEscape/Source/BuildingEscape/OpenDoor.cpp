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
	CloseAngle = Door->GetActorRotation().Yaw;
}

void UOpenDoor::OpenDoor()
{
	Door->SetActorRotation(FRotator(0.f, CloseAngle + OpenAngle, 0.f));
	LastDoorOpenTime = GetWorld()->GetTimeSeconds();
}

void UOpenDoor::CloseDoor()
{
	Door->SetActorRotation(FRotator(0.f, CloseAngle, 0.f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPLate() > 10.f)
	{
		OpenDoor();
	}
	else if ((GetWorld()->GetTimeSeconds() - LastDoorOpenTime) >= CloseDelayInSeconds)
	{
		CloseDoor();
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPLate() const
{
	float TotalMass = 0.f;

	/// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	///Iterate through them adding their masses.
	for (const auto* OverlappingActor : OverlappingActors)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is overlapping"), *OverlappingActor->GetName());
		auto PrimitiveComponent = OverlappingActor->FindComponentByClass<UPrimitiveComponent>();
		if (PrimitiveComponent) {
			TotalMass += PrimitiveComponent->GetMass();
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Total Mass is: %f"), TotalMass);
	
	return TotalMass;
}

