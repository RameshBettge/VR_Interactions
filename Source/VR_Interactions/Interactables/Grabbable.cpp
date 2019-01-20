// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabbable.h"
#include "VR_Controller.h"

// Sets default values
AGrabbable::AGrabbable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	// Create Trigger Sphere Radius is not set programmatically because it depends on mesh.
	MySphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));
	MySphereComponent->bVisible = true;
	// TODO: Set bHiddenInGame to true as soon as debugging is not needed anymore.
	MySphereComponent->bHiddenInGame = false;
	MySphereComponent->SetRelativeLocation(FVector::ZeroVector);

	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AGrabbable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabbable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGrabbable::GetGrabbed(UVR_Controller *Hand)
{
	// TODO: Reference to VR_Controller may be unnecessary and can be removed later.
	this->Hand = Hand;
	bIsGrabbed = true;

	return false;
}

void AGrabbable::UpdateGrab(FVector Pos, FRotator Rot)
{

}

void AGrabbable::Release(FVector Pos, FRotator Rot)
{
	bIsGrabbed = false;
}

