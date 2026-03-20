// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Considerations/UTIL_Consideration.h"
#include "UTIL_ConstantConsideration.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYPROJECT_API UUTIL_ConstantConsideration : public UUTIL_Consideration
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AI|Considerations")
	float ConstantValue;

public:
	virtual float EvaluateConsideration(UBlackboardComponent* BlackboardContext) override;
};
