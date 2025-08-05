// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityAffectables/AffectableArea.h"
#include "Components/BoxComponent.h"
#include "Components/SpecialAbilityComponent.h"
#include "AbilityAffectables/AffectableObject.h"

// Sets default values
AAffectableArea::AAffectableArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initializing Root Component
	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Root Component"));
	SetRootComponent(DefaultRootComponent);

	// Initializing Box Component for overlapping events
	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision Component"));
	BoxCollisionComponent->SetupAttachment(GetRootComponent());
	BoxCollisionComponent->InitBoxExtent(FVector::One());

	// Initializing Special Ability Component
	SpecialAbilityComponent = CreateDefaultSubobject<USpecialAbilityComponent>(TEXT("Special Ability Component"));
	SpecialAbilityComponent->SetAffectableAreaValue(true);

	// Set the max iteration value to the max number of times ability can be performed for consistency
	MaxIteration = SpecialAbilityComponent->GetMaxChargesValue();

}

// Called when the game starts or when spawned
void AAffectableArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAffectableArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AAffectableArea::GetCurrentIterationValue() const
{
	return CurrentIteration;;
}

int AAffectableArea::GetMaxIterationValue() const
{
	return MaxIteration;
}

void AAffectableArea::SetMaxIterationValue(int Value)
{
	if (Value < 0)
	{
		MaxIteration = 0;
		return;
	}

	MaxIteration = Value;
}

void AAffectableArea::AddAffectableObject(AAffectableObject* Object)
{
	// add affectable object to array
	AffectableObjectsList.AddUnique(Object);
}

// This function gets called when Special Ability is used (Listen to event from SpecialAbilityComponent)
void AAffectableArea::ChangeSpaceLayout()
{
	// This is where we address all affectable objects and send the message to toggle visibility based on iteration value
	for (AAffectableObject* Object : AffectableObjectsList)
	{
		if (Object->Implements<UAbilityReaction>())
		{
			Object->ToggleVisibility(CurrentIteration);
		}
	}

	// call rotate current iteration to change ID to send next time special ability is used
	RotateCurrentIteration();
}

void AAffectableArea::RotateCurrentIteration()
{
	// Reset Current Iteration value if reached max
	if (CurrentIteration >= MaxIteration)
	{
		CurrentIteration = 0;
		return;
	}

	// Increment current iteration value
	++CurrentIteration;

}

