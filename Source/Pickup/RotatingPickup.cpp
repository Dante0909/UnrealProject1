// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPickup.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
URotatingPickup::URotatingPickup()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotatingPickup::BeginPlay()
{
	Super::BeginPlay();
	TimeElapsed = 0;


	// ...
}


// Called every frame
void URotatingPickup::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetOwner()->AddActorLocalRotation(FRotator(0, 1, 0) * RotateSpeed * DeltaTime);

	TimeElapsed += DeltaTime;
	

	GetOwner()->AddActorLocalOffset(FVector(0, 0, FMath::Sin(TimeElapsed * HoverSpeed) * HoverAmplitude));

	//GetOwner()->AddActorLocalOffset()
	// ...
}

