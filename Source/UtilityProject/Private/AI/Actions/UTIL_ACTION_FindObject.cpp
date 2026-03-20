// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Actions/UTIL_ACTION_FindObject.h"

#include "UTIL_Actor.h"
#include "AI/UTIL_AICharacter.h"
#include "AI/UTIL_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UUTIL_ACTION_FindObject::ExecuteAction(UBlackboardComponent* BlackboardContext)
{
	Super::ExecuteAction(BlackboardContext);

	// Can't be in the initialize as actors found is constantly changing
	
	if (!BrainControllerReference || BrainControllerReference->GetUtilityActorsFound().IsEmpty())
	{
		return;
	}
	
	for (AUTIL_Actor* CurrentActor : BrainControllerReference->GetUtilityActorsFound())
	{
		if (!CurrentActor || !CurrentActor->ActorUtilityTags.HasAny(TagsInRelevantActors) || ActorsRelevantToAction.Contains(CurrentActor))
		{
			continue;
		}

		ActorsRelevantToAction.AddUnique(CurrentActor);
	}

	float DistanceToActor = TNumericLimits<float>::Max();
	AUTIL_Actor* ClosestActor = nullptr;
	for (AUTIL_Actor* ActorToCalculate : ActorsRelevantToAction)
	{
		if (!ActorToCalculate)
		{
			continue;
		}
		
		const float NewDistanceToCompare = FVector::Distance(ActorToCalculate->GetActorLocation(), BrainControllerReference->GetOwnerCharacter()->GetActorLocation());
		if (NewDistanceToCompare < DistanceToActor)
		{
			DistanceToActor = NewDistanceToCompare;
			ClosestActor = ActorToCalculate;
		}
	}

	if (ClosestActor)
	{
		BlackboardContext->SetValueAsVector(VectorKeyName, ClosestActor->GetActorLocation());
		BlackboardContext->SetValueAsFloat(DistanceToTargetKeyName, DistanceToActor);

		DrawDebugSphere(GetWorld(), ClosestActor->GetActorLocation(), 100.f, 16, FColor::Yellow);
	}
}
