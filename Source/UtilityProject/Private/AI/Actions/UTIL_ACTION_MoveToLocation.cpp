// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Actions/UTIL_ACTION_MoveToLocation.h"

#include "AI/UTIL_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UUTIL_ACTION_MoveToLocation::InitializeAction(UBlackboardComponent* BlackboardContext)
{
	Super::InitializeAction(BlackboardContext);
}

float UUTIL_ACTION_MoveToLocation::CalculateActionUtility(UBlackboardComponent* BlackboardContext)
{
	return Super::CalculateActionUtility(BlackboardContext);
}

void UUTIL_ACTION_MoveToLocation::ExecuteAction(UBlackboardComponent* BlackboardContext)
{
	Super::ExecuteAction(BlackboardContext);

	AIControllerRef = Cast<AUTIL_AIController>(BlackboardContext->GetValueAsObject(AIControllerKeyName));
	Destination = BlackboardContext->GetValueAsVector(LocationKeyName);

	if (AIControllerRef)
	{
		AIControllerRef->MoveToLocation(Destination, 100.f);
	}
}
