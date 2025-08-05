// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/AbilityReaction.h"
#include "AffectableObject.generated.h"

UCLASS()
class DRUIDMECHANICS_API AAffectableObject : public AActor, public IAbilityReaction
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetReactionIDValue, BlueprintSetter = SetReactionIDValue, Category = "Ability Reaction")
	int ReactionID{ 0 };

	UPROPERTY(VisibleAnywhere, BlueprintSetter = SetIsHiddenInGameValue, Category = "Ability Reaction")
	bool bIsHiddenInGame{ false };

	UPROPERTY(VisibleAnywhere, BlueprintSetter = SetIsCollisionEnabledValue, Category = "Ability Reaction")
	bool bIsCollisionEnabled{ true };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Affectable Object")
	USceneComponent* DefaultRootComponent{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Affectable Object")
	UStaticMeshComponent* AffectableObjectMesh{ nullptr };

public:	
	// Sets default values for this actor's properties
	AAffectableObject();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ACCESSORS/GETTERS
	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Ability Reaction")
	int GetReactionIDValue() const;

	// MUTATORS/SETTERS 
	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Ability Reaction")
	void SetReactionIDValue(int Value);

	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Ability Reaction")
	void SetIsHiddenInGameValue(bool Value);
	
	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Ability Reaction")
	void SetIsCollisionEnabledValue(bool Value);

	// Interface function
	virtual void ToggleVisibility(int ID) override;

};
