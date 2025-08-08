// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AffectableArea.generated.h"

UCLASS()
class DRUIDMECHANICS_API AAffectableArea : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetCurrentIterationValue, Category = "Special Ability")
	int CurrentIteration{ 0 };

	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetMaxIterationValue, BlueprintSetter = SetMaxIterationValue, Category = "Special Ability")
	int MaxIteration{ 3 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* DefaultRootComponent{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Ability")
	class UBoxComponent* BoxCollisionComponent{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Ability")
	class USpecialAbilityComponent* SpecialAbilityComponent{ nullptr };

	// Change array of Actors to AffectableObjects once declared
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Ability")
	TArray<class AAffectableObject*> AffectableObjectsList{};

	UFUNCTION(BlueprintCallable, Category = "Special Ability")
	void ChangeSpaceLayout();

	UFUNCTION(BlueprintCallable, Category = "Special Ability")
	void RotateCurrentIteration();

public:
	// Sets default values for this actor's properties
	AAffectableArea();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ACCESSORS/GETTERS
	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Special Ability")
	int GetCurrentIterationValue() const;

	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Special Ability")
	int GetMaxIterationValue() const;

	// MUTABLES/SETTERS
	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Special Ability")
	void SetMaxIterationValue(int Value);

	UFUNCTION(BlueprintCallable, Category = "Special Ability")
	void AddAffectableObject(class AAffectableObject* Object);

};
