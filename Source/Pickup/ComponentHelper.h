// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

/**
 * 
 */
class PICKUP_API ComponentHelper
{
public:
	ComponentHelper();

	static UActorComponent* GetComponentByName(AActor* actor, FString name);

	~ComponentHelper();
};
