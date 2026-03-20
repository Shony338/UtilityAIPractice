// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "UTIL_UtilityAction.generated.h"

class AUTIL_Actor;
class AUTIL_AIController;
class UUTIL_Consideration;
class UBlackboardComponent;

USTRUCT(Blueprintable, BlueprintType)
struct FUTIL_ActionConsiderationStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction")
	float ConsiderationModifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction")
	TObjectPtr<UUTIL_Consideration> Consideration;

	FUTIL_ActionConsiderationStruct() : ConsiderationModifier(1.f), Consideration(nullptr){}

	FUTIL_ActionConsiderationStruct(float NewConsiderationModifier, UUTIL_Consideration* NewConsideration) : ConsiderationModifier(NewConsiderationModifier),  Consideration(NewConsideration){}
};

/**
 * 
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class UTILITYPROJECT_API UUTIL_UtilityAction : public UObject
{
	GENERATED_BODY()

public:
	virtual void InitializeAction(UBlackboardComponent* BlackboardContext);

	virtual float CalculateActionUtility(UBlackboardComponent* BlackboardContext);

	virtual void ExecuteAction(UBlackboardComponent* BlackboardContext);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction")
	FName BrainKeyName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction")
	FUTIL_ActionConsiderationStruct ActionConsideration;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction")
	uint8 bActionUsesTags : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI|UtilityAction", meta = (EditCondition = bActionUsesTags))
	FGameplayTagContainer TagsInRelevantActors;

	TObjectPtr<AUTIL_AIController> BrainControllerReference;

	UPROPERTY()
	TArray<TObjectPtr<AUTIL_Actor>> ActorsRelevantToAction;
	
};
