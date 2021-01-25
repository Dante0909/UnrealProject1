// Fill out your copyright notice in the Description page of Project Settings.

#include "SpeedPickup.h"
#include "Components/StaticMeshComponent.h"
#include "PickupCharacter.h"
//#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASpeedPickup::ASpeedPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpeedPickup::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpeedPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void ASpeedPickup::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(APickupCharacter::StaticClass()))
	{
		//specific logic for my specialized pickup
		Cast<APickupCharacter>(OtherActor)->SpeedUp(speedIncrease, cooldown);
		/*UCharacterMovementComponent* cmc = Cast<APickupCharacter>(OtherActor)->GetCharacterMovement();
		cmc->MaxWalkSpeed = cmc->MaxWalkSpeed * speedIncrease;*/
		Destroy();
	}

}
