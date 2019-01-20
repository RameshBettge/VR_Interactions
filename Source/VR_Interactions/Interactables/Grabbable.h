// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../VR_Controller.h"
#include "Components/StaticMeshComponent.h"
#include "Grabbable.generated.h"

UCLASS()
class VR_INTERACTIONS_API AGrabbable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGrabbable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		USphereComponent* MySphereComponent;

	bool bIsGrabbed;

private:
	//UVR_Controller* Hand;

public:
	// TODO: Make reference to UVR_Controller possible. May be broken because of Grabbable.cpp's position in folder hierarchy.
	//virtual bool GetGrabbed(UVR_Controller *Hand);

	virtual void UpdateGrab(FVector Pos, FRotator Rot);

	virtual void Release(FVector Pos, FRotator Rot);

};
