// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeToHurt.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PickupProjectile.h"
#include "Engine/Engine.h"


// Sets default values
ACubeToHurt::ACubeToHurt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	CubeRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CubeRoot"));
	RootComponent = CubeRoot;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	BoxMesh->AttachToComponent(CubeRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);


	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	BoxCollision->SetCollisionProfileName("OverlapAll");
	BoxCollision->SetGenerateOverlapEvents(true);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACubeToHurt::OnCharacterOverlap);
	BoxCollision->AttachToComponent(CubeRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);
	
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("Material'/Game/material3.material3'"));
	
	if (FoundMaterial.Succeeded()) {
		material3 = FoundMaterial.Object;
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial2(TEXT("Material'/Game/material2.material2'"));
	if (FoundMaterial.Succeeded()) {
		material2 = FoundMaterial2.Object;
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial1(TEXT("Material'/Game/material1.material1'"));
	if (FoundMaterial.Succeeded()) {
		material1 = FoundMaterial1.Object;
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (FoundMesh.Succeeded()) {
		BoxMesh->SetStaticMesh(FoundMesh.Object);
	}

	
}

// Called when the game starts or when spawned
void ACubeToHurt::BeginPlay()
{
	Super::BeginPlay();
	
	if(BoxMesh) BoxMesh->SetMaterial(0, material3);
}

// Called every frame
void ACubeToHurt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
void ACubeToHurt::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	
	/*if (OtherActor != nullptr && OtherActor != this && OtherComp != nullptr) {
		if (OtherActor->IsA(APickupProjectile::StaticClass())) {
			ACubeToHurt::Hit();
		}
	}*/
}

void ACubeToHurt::Hit() {
	hp--;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("hp = %i"), hp));
	if (BoxMesh) {
		if (hp == 2)BoxMesh->SetMaterial(0, material2);
		else if (hp == 1)BoxMesh->SetMaterial(0, material1);
		else Destroy();
	}
	
}

