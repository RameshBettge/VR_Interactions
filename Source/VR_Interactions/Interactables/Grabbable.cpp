// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabbable.h"

// Sets default values
AGrabbable::AGrabbable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	MySphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));
	MySphereComponent->bVisible = true;
	MySphereComponent->bHiddenInGame = false;
	//MySphereComponent->SetSphereRadius()

	//RootComponent = MySphereComponent;
	RootComponent = Mesh;

	//MySphereComponent->SetupAttachment(Mesh);

	//MySphereComponent->SetupAttachment(GetOwner());
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

bool AGrabbable::GetGrabbed(UVR_Controller Hand)
{
	return false;
}

void AGrabbable::UpdateGrab(FVector Pos, FRotator Rot)
{
}

void AGrabbable::Release(FVector Pos, FRotator Rot)
{
}

