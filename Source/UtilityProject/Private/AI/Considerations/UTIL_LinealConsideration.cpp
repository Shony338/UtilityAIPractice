// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Considerations/UTIL_LinealConsideration.h"
#include "Curves/CurveFloat.h"
#include "BehaviorTree/BlackboardComponent.h"

float UUTIL_LinealConsideration::EvaluateConsideration(UBlackboardComponent* BlackboardContext)
{
	if (!BlackboardContext || !ConsiderationCurve)
	{
		return 0.f;
	}
	ConsiderationCurve->FloatCurve.UpdateOrAddKey(0.f, 0.f);
	ConsiderationCurve->FloatCurve.UpdateOrAddKey(1.f, BlackboardContext->GetValueAsFloat(ContextRange));
	const float ValueToEvaluate = BlackboardContext->GetValueAsFloat(KeyNameToEvaluate);
	return ConsiderationCurve->GetFloatValue(ValueToEvaluate);
}
