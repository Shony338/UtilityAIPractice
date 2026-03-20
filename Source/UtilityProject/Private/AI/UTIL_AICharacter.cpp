// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/UTIL_AICharacter.h"

#include "AI/UTIL_AIController.h"
#include "Components/SphereComponent.h"

#define UTIL_Object       ECC_GameTraceChannel1

// Sets default values
AUTIL_AICharacter::AUTIL_AICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WorldDetectorSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("WorldDetectorSphereComponent"));
	WorldDetectorSphereComponent->SetupAttachment(RootComponent);
	WorldDetectorSphereComponent->SetCollisionObjectType(UTIL_Object);
	WorldDetectorSphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	WorldDetectorSphereComponent->SetCollisionResponseToChannel(UTIL_Object, ECR_Overlap);
	
}

// Called when the game starts or when spawned
void AUTIL_AICharacter::BeginPlay()
{
	Super::BeginPlay();

	AIControllerRef = Cast<AUTIL_AIController>(GetController());
	
	WorldDetectorSphereComponent->OnComponentBeginOverlap.AddDynamic(AIControllerRef, &AUTIL_AIController::ObjectInContextRange);
	WorldDetectorSphereComponent->OnComponentEndOverlap.AddDynamic(AIControllerRef, &AUTIL_AIController::ObjectLeftContextRange);
}

// Called every frame
void AUTIL_AICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUTIL_AICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}