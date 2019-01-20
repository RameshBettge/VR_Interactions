// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_Controller.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"



// Sets default values for this component's properties
UVR_Controller::UVR_Controller()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	MySphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));
	MySphereComponent->bVisible = true;
	MySphereComponent->bHiddenInGame = true;
	//MySphereComponent->SetSphereRadius()

	MySphereComponent->SetupAttachment(this);
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

TArray<AActor*> UVR_Controller::GetActorsInRange()
{
	TArray<AActor*> ActorsInRange = TArray<AActor*>();

	//const TArray<EnumToByte<EObjectTypeQuery>> ObjectTypes;
	//TArray<TEnumAsByte<enum EObjectTypeQuery>> ObjectTypes;
	////const TArray<EObjectTypeQuery> ObjectTypes;

	//UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetComponentLocation(), 100.f, ObjectTypes, AActor::StaticClass(), TArray<AActor*>(), ActorsInRange);


	return TArray<AActor*>();
}

