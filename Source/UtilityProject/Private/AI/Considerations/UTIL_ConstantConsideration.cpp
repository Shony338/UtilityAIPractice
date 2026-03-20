// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Considerations/UTIL_ConstantConsideration.h"

float UUTIL_ConstantConsideration::EvaluateConsideration(UBlackboardComponent* BlackboardContext)
{
	return ConstantValue;
}
