// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SpecialAbilityComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
USpecialAbilityComponent::USpecialAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentCharges = MaxCharges;
	
}


// Called when the game starts
void USpecialAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
}


// Called every frame
void USpecialAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}


int USpecialAbilityComponent::GetCurrentChargesValue() const
{
	return CurrentCharges;
}

int USpecialAbilityComponent::GetMaxChargesValue() const
{
	return MaxCharges;
}

bool USpecialAbilityComponent::GetWithinRangeValue() const
{
	return bIsWithinRange;
}

bool USpecialAbilityComponent::GetAffectableAreaValue() const
{
	return bIsAffectableArea;
}


void USpecialAbilityComponent::SetMaxChargesValue(int Value)
{
	if (Value < 0)
	{
		MaxCharges = 0;
		return;
	}

	MaxCharges = Value;
}

void USpecialAbilityComponent::SetWithinRangeValue(bool Value)
{
	bIsWithinRange = Value;
}

void USpecialAbilityComponent::SetAffectableAreaValue(bool Value)
{
	bIsAffectableArea = Value;
}

bool USpecialAbilityComponent::CanPerformAbility() const
{
	return bIsWithinRange && (CurrentCharges > 0);
}

void USpecialAbilityComponent::PerformAbility()
{
	// Check if we can perfom the ability
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, CanPerformAbility() ? TEXT("True") : TEXT("False"));
	}
}

void USpecialAbilityComponent::RechargeAbility(int Value)
{
	if (Value < 0)
	{
		return;
	}

	CurrentCharges = UKismetMathLibrary::FClamp(CurrentCharges + Value, 0, MaxCharges);
}

void USpecialAbilityComponent::ReduceChargeValue()
{
	CurrentCharges = UKismetMathLibrary::FClamp(CurrentCharges - 1, 0, MaxCharges);
}

