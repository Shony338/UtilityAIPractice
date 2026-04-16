// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/UTIL_AIController.h"

#include "UTIL_Actor.h"
#include "AI/UTIL_AICharacter.h"
#include "AI/Actions/UTIL_UtilityAction.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SphereComponent.h"

#define UTIL_Object       ECC_GameTraceChannel1

#define print(message, color, time, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, time, color, FString::Printf(TEXT(message), __VA_ARGS__)); UE_LOG(LogTemp, Log, TEXT(message), __VA_ARGS__);}
#define printError(message, color, time, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, time, color, FString::Printf(TEXT(message), __VA_ARGS__)); UE_LOG(LogTemp, Error, TEXT(message), __VA_ARGS__);}

AUTIL_AIController::AUTIL_AIController()
{
	bDebugUtilityAI = false;
	HighestValue = 0.f;

	BlackboardContext = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardContext"));
}

void AUTIL_AIController::ObjectInContextRange(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AUTIL_Actor* UtilityActor = Cast<AUTIL_Actor>(OtherActor);
	if (!UtilityActor)
	{
		return;
	}

	FoundActors.Add(UtilityActor);
}

void AUTIL_AIController::ObjectLeftContextRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AUTIL_Actor* UtilityActor = Cast<AUTIL_Actor>(OtherActor);
	if (!UtilityActor)
	{
		return;
	}

	FoundActors.Remove(UtilityActor);
}

void AUTIL_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	OwnerCharacter = Cast<AUTIL_AICharacter>(InPawn);
	
	if (!OwnerCharacter)
	{
		return;
	}

	const TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes { UEngineTypes::ConvertToObjectType(UTIL_Object) };
	const TArray<AActor*> ActorsToIgnore;
	TArray<AActor*> InRangeActors;
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), OwnerCharacter->GetActorLocation(), OwnerCharacter->GetWorldDetectorSphere()->GetScaledSphereRadius(), ObjectTypes, AUTIL_Actor::StaticClass(), ActorsToIgnore, InRangeActors);

	for (AActor* ActorInRange : InRangeActors)
	{
		AUTIL_Actor* UtilityActorInRange = Cast<AUTIL_Actor>(ActorInRange);
		if (UtilityActorInRange)
		{
			FoundActors.Add(UtilityActorInRange);
		}
	}

	if (BlackboardContext)
	{
		BlackboardContext->SetValueAsObject(BrainKeyName, this);
		BlackboardContext->SetValueAsFloat(ContextRange, OwnerCharacter->GetWorldDetectorSphere()->GetScaledSphereRadius());

		for (UUTIL_UtilityAction* CurrentAction : UtilityActions)
		{
			if (!CurrentAction)
			{
				continue;
			}
			
			CurrentAction->InitializeAction(BlackboardContext);
		}
	}
}

void AUTIL_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDebugUtilityAI)
	{
		DebugAI(DeltaTime);
	}

	if (!BlackboardContext)
	{
		printError("THE CONTEXT IS YET TO BE ASSIGNED: ", FColor::Red, DeltaTime, 0);
		return;
	}

	UpdateContext();
	
	SelectedAction = nullptr;
	HighestValue = 0.f;

	for (UUTIL_UtilityAction* CurrentAction : UtilityActions)
	{
		if (!CurrentAction)
		{
			continue;
		}

		const float ActionValue = CurrentAction->CalculateActionUtility(BlackboardContext);
		if (ActionValue >= HighestValue)
		{
			HighestValue = ActionValue;
			SelectedAction = CurrentAction;
		}
	}

	if (SelectedAction)
	{
		SelectedAction->ExecuteAction(BlackboardContext);
	}
}

void AUTIL_AIController::UpdateContext()
{
	
}

void AUTIL_AIController::DebugAI(const float DeltaTime)
{
	print("Action Value: %f", FColor::Yellow, DeltaTime, HighestValue);
	print("Selected Action: %s", FColor::Yellow, DeltaTime, SelectedAction ? *SelectedAction->GetName() : *FString("No Action Selected"));
	print("Debugging AI: %s", FColor::Yellow, DeltaTime, OwnerCharacter ? *OwnerCharacter->GetName() : *FString("Controller has no owner"));
}
