// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePickup.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "PickupCharacter.h"

// Sets default values
ABasePickup::ABasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);

	PickupCollision = CreateDefaultSubobject<USphereComponent>(TEXT("PickupCollision"));
	PickupCollision->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	PickupCollision->SetCollisionProfileName("OverlapAll");
	PickupCollision->SetGenerateOverlapEvents(true);
	PickupCollision->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnCharacterOverlap);
	PickupCollision->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);
	
}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePickup::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{


}
