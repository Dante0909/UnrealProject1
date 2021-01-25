// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

UCLASS()
class PICKUP_API ABasePickup : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		class USceneComponent* PickupRoot;
	UPROPERTY(EditAnywhere)
		class USphereComponent* PickupCollision;
	

	
public:	
	// Sets default values for this actor's properties
	ABasePickup();
	
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PickupMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		virtual void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
