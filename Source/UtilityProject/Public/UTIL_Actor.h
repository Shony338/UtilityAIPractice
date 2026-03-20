// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "UTIL_Actor.generated.h"

UCLASS()
class UTILITYPROJECT_API AUTIL_Actor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UtilityAI|Tags")
	FGameplayTagContainer ActorUtilityTags;
	
public:	
	// Sets default values for this actor's properties
	AUTIL_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
