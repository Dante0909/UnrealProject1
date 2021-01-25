// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "CubeToHurt.generated.h"

UCLASS()
class PICKUP_API ACubeToHurt : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		class USceneComponent* CubeRoot;
	
	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;
public:	
	// Sets default values for this actor's properties
	ACubeToHurt();
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* BoxMesh;
	int hp = 3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Hit();
	
	
	
	UPROPERTY(EditAnywhere)
		class UMaterial* material3;
	UPROPERTY(EditAnywhere)
		class UMaterial* material2;
	UPROPERTY(EditAnywhere)
		class UMaterial* material1;

	

	UFUNCTION()
		virtual void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
