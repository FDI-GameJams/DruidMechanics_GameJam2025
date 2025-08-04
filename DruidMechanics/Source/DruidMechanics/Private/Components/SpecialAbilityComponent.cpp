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

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, 
			FString::Printf(TEXT("Charges = %d"), CurrentCharges)
		);
	}
	
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

bool USpecialAbilityComponent::GetIsAbilityCurrentlyPerformingValue() const
{
	return bIsAbilityCurrentlyPerforming;
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

void USpecialAbilityComponent::SetIsAbilityCurrentlyPerformingValue(bool Value)
{
	bIsAbilityCurrentlyPerforming = Value;
}

bool USpecialAbilityComponent::CanPerformAbility() const
{
	// also check if ability is being used
	// --> there's a delay between performing ability, changes taking place, and finishing performing ability
	return bIsWithinRange && (CurrentCharges > 0) && (!bIsAbilityCurrentlyPerforming);
}

void USpecialAbilityComponent::PerformAbility()
{
	// Check if we can perfom the ability
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, CanPerformAbility() ? TEXT("True") : TEXT("False"));
	}

	if (!CanPerformAbility())
	{
		return;
	}

	// reduce charge value 
	ReduceChargeValue();
	// perform ability
	OnAbilityPerformedDelegate.Broadcast();
}

void USpecialAbilityComponent::RechargeAbility(int Value)
{
	if (Value < 0)
	{
		return;
	}

	CurrentCharges = UKismetMathLibrary::FClamp(CurrentCharges + Value, 0, MaxCharges);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
			FString::Printf(TEXT("Charges = %d"), CurrentCharges)
		);
	}
}

void USpecialAbilityComponent::ReduceChargeValue()
{
	CurrentCharges = UKismetMathLibrary::FClamp(CurrentCharges - 1, 0, MaxCharges);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
			FString::Printf(TEXT("Charges = %d"), CurrentCharges)
		);
	}
}

