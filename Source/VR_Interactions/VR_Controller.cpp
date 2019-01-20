// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_Controller.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"

// For logging on screen
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>



// Sets default values for this component's properties
UVR_Controller::UVR_Controller()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Assign Object Typed (=Collision channels) to the GrabFilter
	GrabFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
	GrabFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));
	GrabFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_PhysicsBody));
}


// Called when the game starts
void UVR_Controller::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UVR_Controller::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UVR_Controller::GrabClosest()
{
	bool bSucceeded = false;

	TArray<AActor*> GrabbablesInRange = TArray<AActor*>();

	// Get Grabbables in GrabRadius and saves them in Array
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetComponentLocation(), GrabRadius, GrabFilter, AGrabbable::StaticClass(), TArray<AActor*>(), GrabbablesInRange);
	UE_LOG(LogTemp, Warning, TEXT("Grabbables found: %d"), GrabbablesInRange.Num());

	if (GrabbablesInRange.Num() > 0)
	{
		bSucceeded = true;

		// Display Debug Message on screen if at least one grabbable object is found TODO: Remove later
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Found sth. to grab!"), true, FVector2D(2, 2));
	}

	// Step through all found grabbables TODO: assign the closest one to variable GrabbedObject
	for (int16 i = 0; i < GrabbablesInRange.Num(); i++)
	{
		AGrabbable *CastedGrabbable = Cast<AGrabbable>(GrabbablesInRange[i]);
		if (CastedGrabbable)
		{
			UE_LOG(LogTemp, Warning, TEXT("Grabbable in range: %s"), *GrabbablesInRange[i]->GetName());
		}
	}

	// Let caller know if something was grabbed.
	return bSucceeded;
}

void UVR_Controller::Release()
{
	// Let the grabbed object choose their behaviour independently
	if (GrabbedObject)
	{
		GrabbedObject->Release(GetComponentLocation(), GetComponentRotation());
	}

	GrabbedObject = nullptr;
}

