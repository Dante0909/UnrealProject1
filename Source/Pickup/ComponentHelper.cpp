// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentHelper.h"

ComponentHelper::ComponentHelper()
{
}

UActorComponent* ComponentHelper::GetComponentByName(AActor* actor, FString name) {

	TArray<UActorComponent*> childrenComponents;
	actor->GetComponents<UActorComponent>(childrenComponents);


	for (int i = 0; i < childrenComponents.Num(); ++i) {

		if (childrenComponents[i] && childrenComponents[i]->GetName() == name) {
			return childrenComponents[i];
		}
	}

	return NULL;
}

ComponentHelper::~ComponentHelper()
{
}
