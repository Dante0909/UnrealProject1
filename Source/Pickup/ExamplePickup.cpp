
// Fill out your copyright notice in the Description page of Project Settings.


#include "ExamplePickup.h"
#include "Components/MeshComponent.h"
#include "PickupCharacter.h"


// Sets default values
AExamplePickup::AExamplePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void AExamplePickup::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExamplePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExamplePickup::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(APickupCharacter::StaticClass())) 
	{
		//specific logic for my specialized pickup

		Destroy();
	}
	
}

