// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Interactables/Grabbable.h"
#include "VR_Controller.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VR_INTERACTIONS_API UVR_Controller : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UVR_Controller();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Variables and References
public:
	//UPROPERTY(BlueprintReadWrite)
		float GrabRadius;

private:

	TArray<TEnumAsByte<enum EObjectTypeQuery>> GrabFilter;

	AGrabbable * GrabbedObject = nullptr;


	//Functions
public:
	UFUNCTION(BlueprintCallable)
		bool GrabClosest();

	UFUNCTION(BlueprintCallable)
		void Release();
};
