// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorChange.h"
#include "Components/StaticMeshComponent.h"
#include "ComponentHelper.h"

// Sets default values for this component's properties
UColorChange::UColorChange()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UColorChange::BeginPlay()
{
	Super::BeginPlay();
	Cube = Cast<UStaticMeshComponent>(ComponentHelper::GetComponentByName(GetOwner(), "Cube"));

	// ...
	
}


// Called every frame
void UColorChange::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UColorChange::OnOverlapBeginFunction() {
	if(Cube) Cube->SetMaterial(0, Green);
	
}
void UColorChange::OnOverlapEndFunction() {
	if(Cube) Cube->SetMaterial(0, Red);
	
}

