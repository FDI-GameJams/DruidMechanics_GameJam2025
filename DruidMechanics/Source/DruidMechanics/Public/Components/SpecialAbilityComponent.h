// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpecialAbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRUIDMECHANICS_API USpecialAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	// private properties
	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetCurrentChargesValue, Category = "Special Ability")
	int CurrentCharges{ 0 };

	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetMaxChargesValue, BlueprintSetter = SetMaxChargesValue, Category = "Special Ability")
	int MaxCharges{ 3 };

	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetWithinRangeValue, BlueprintSetter = SetWithinRangeValue, Category = "Special Ability")
	bool bIsWithinRange{ false };

	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetAffectableAreaValue, BlueprintSetter = SetAffectableAreaValue, Category = "Special Ability")
	bool bIsAffectableArea{ false };


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Ability 
	UFUNCTION(BlueprintPure, Category = "Special Ability")
	bool CanPerformAbility() const;

	UFUNCTION(BlueprintCallable, Category = "Special Ability")
	void PerformAbility();


public:
	// Sets default values for this component's properties
	USpecialAbilityComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ACCESSORS/GETTERS
	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Special Ability")
	int GetCurrentChargesValue() const;

	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Special Ability")
	int GetMaxChargesValue() const;

	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Special Ability")
	bool GetWithinRangeValue() const;

	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Special Ability")
	bool GetAffectableAreaValue() const;

	// MUTABLES/SETTERS
	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Special Ability")
	void SetMaxChargesValue(int Value);

	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Special Ability")
	void SetWithinRangeValue(bool Value);

	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Special Ability")
	void SetAffectableAreaValue(bool Value);




};
