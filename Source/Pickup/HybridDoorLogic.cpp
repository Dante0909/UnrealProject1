// Fill out your copyright notice in the Description page of Project Settings.


#include "HybridDoorLogic.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ComponentHelper.h"

// Sets default values for this component's properties
UHybridDoorLogic::UHybridDoorLogic()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHybridDoorLogic::BeginPlay()
{
	Super::BeginPlay();

	// ...
	DoorMesh = Cast<UStaticMeshComponent>(ComponentHelper::GetComponentByName(GetOwner(), "DoorMesh"));
}


// Called every frame
void UHybridDoorLogic::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHybridDoorLogic::OnOverlapFunction() 
{
	if (DoorMesh) {
		DoorMesh->SetVisibility(false);
		DoorMesh->SetCollisionProfileName("NoCollision");
	}
	
}
