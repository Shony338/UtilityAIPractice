// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UTIL_AIController.generated.h"

class AUTIL_Actor;
class AUTIL_AICharacter;
class UUTIL_UtilityAction;
/**
 * 
 */
UCLASS()
class UTILITYPROJECT_API AUTIL_AIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|UtilityAI")
	UBlackboardComponent* BlackboardContext;

protected:
	UPROPERTY()
	TObjectPtr<AUTIL_AICharacter> OwnerCharacter;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UtilityAI")
	uint8 bDebugUtilityAI : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UtilityAI")
	TArray<TObjectPtr<UUTIL_UtilityAction>> UtilityActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UtilityAI")
	FName BrainKeyName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UtilityAI")
	FName ContextRange;

	UPROPERTY()
	TObjectPtr<UUTIL_UtilityAction> SelectedAction;

	float HighestValue;

	UPROPERTY()
	TArray<AUTIL_Actor*> FoundActors;

public:
	AUTIL_AIController();
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	const TArray<AUTIL_Actor*>& GetUtilityActorsFound() const { return FoundActors; }

	UFUNCTION()
	void ObjectInContextRange(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void ObjectLeftContextRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	AUTIL_AICharacter* GetOwnerCharacter() const { return OwnerCharacter; }

protected:
	virtual void OnPossess(APawn* InPawn) override;
	
	void UpdateContext();

	void DebugAI(const float DeltaTime);

};
