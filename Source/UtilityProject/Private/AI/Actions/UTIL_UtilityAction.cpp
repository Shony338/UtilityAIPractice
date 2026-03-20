// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Actions/UTIL_UtilityAction.h"

#include "AI/UTIL_AIController.h"
#include "AI/Considerations/UTIL_Consideration.h"
#include "BehaviorTree/BlackboardComponent.h"

void UUTIL_UtilityAction::InitializeAction(UBlackboardComponent* BlackboardContext)
{
	if (!BlackboardContext)
	{
		return;
	}
	
	if (UObject* BrainObject =  BlackboardContext->GetValueAsObject(BrainKeyName))
	{
		BrainControllerReference = Cast<AUTIL_AIController>(BrainObject);
	}
}

float UUTIL_UtilityAction::CalculateActionUtility(UBlackboardComponent* BlackboardContext)
{
	if (!ActionConsideration.Consideration)
	{
		return 0.f;
	}
	
	return ActionConsideration.Consideration->EvaluateConsideration(BlackboardContext) * ActionConsideration.ConsiderationModifier;
}

void UUTIL_UtilityAction::ExecuteAction(UBlackboardComponent* BlackboardContext)
{
}
