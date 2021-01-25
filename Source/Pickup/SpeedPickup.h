// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "GameFramework/Actor.h"
#include "SpeedPickup.generated.h"



UCLASS()
class PICKUP_API ASpeedPickup : public ABasePickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeedPickup();
	int speedIncrease = 2;
	float cooldown = 5;
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
