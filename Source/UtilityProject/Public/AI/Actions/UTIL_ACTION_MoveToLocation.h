// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Actions/UTIL_UtilityAction.h"
#include "UTIL_ACTION_MoveToLocation.generated.h"

class AUTIL_AIController;
/**
 * 
 */
UCLASS()
class UTILITYPROJECT_API UUTIL_ACTION_MoveToLocation : public UUTIL_UtilityAction
{
	GENERATED_BODY()

protected:
	TObjectPtr<AUTIL_AIController> AIControllerRef;
	
	FVector Destination;

	UPROPERTY(EditDefaultsOnly, Category = "MoveToLocationAction")
	FName AIControllerKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "MoveToLocationAction")
	FName LocationKeyName;

public:
	virtual void InitializeAction(UBlackboardComponent* BlackboardContext) override;

	virtual float CalculateActionUtility(UBlackboardComponent* BlackboardContext) override;

	virtual void ExecuteAction(UBlackboardComponent* BlackboardContext) override;
};
