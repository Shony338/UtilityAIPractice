// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Considerations/UTIL_Consideration.h"
#include "UTIL_LinealConsideration.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYPROJECT_API UUTIL_LinealConsideration : public UUTIL_Consideration
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Considerations")
	FName ContextRange;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Considerations")
	FName KeyNameToEvaluate;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Considerations")
	TObjectPtr<UCurveFloat> ConsiderationCurve;

public:
	virtual float EvaluateConsideration(UBlackboardComponent* BlackboardContext) override;
};
