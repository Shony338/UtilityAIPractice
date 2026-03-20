// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Actions/UTIL_UtilityAction.h"
#include "UTIL_ACTION_FindObject.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYPROJECT_API UUTIL_ACTION_FindObject : public UUTIL_UtilityAction
{
	GENERATED_BODY()

protected:
	FVector DistanceToObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction|FindObject")
	FName VectorKeyName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction|FindObject")
	FName DistanceToTargetKeyName;

public:
	virtual void ExecuteAction(UBlackboardComponent* BlackboardContext) override;
	
};
