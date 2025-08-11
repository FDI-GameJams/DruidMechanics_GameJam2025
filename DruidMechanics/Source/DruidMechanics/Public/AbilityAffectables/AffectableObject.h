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
	UPROPERTY(EditAnywhere, BlueprintGetter = GetReactionIDValue, BlueprintSetter = SetReactionIDValue, Category = "Ability Reaction")
	int ReactionID{ 0 };
	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetMaxReactionID, BlueprintSetter = SetMaxReactionID, Category = "Ability Reaction")
	int MaxReactionID{ 3 };

	UPROPERTY(EditAnywhere, BlueprintSetter = SetIsHiddenInGameValue, Category = "Ability Reaction")
	bool bIsHiddenInGame{ false };

	UPROPERTY(EditAnywhere, BlueprintSetter = SetIsCollisionEnabledValue, Category = "Ability Reaction")
	bool bIsCollisionEnabled{ true };

	UPROPERTY(EditAnywhere, BlueprintGetter = GetObjectMesh, BlueprintSetter = SetObjectMesh, Category = "Affectable Object")
	UStaticMesh* ObjectMesh{ nullptr };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Affectable Object")
	USceneComponent* DefaultRootComponent{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Affectable Object")
	UStaticMeshComponent* ObjectMeshComponent{ nullptr };


public:	
	// Sets default values for this actor's properties
	AAffectableObject();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ACCESSORS/GETTERS
	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Ability Reaction")
	int GetReactionIDValue() const;

	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Ability Reaction")
	int GetMaxReactionID() const;

	UFUNCTION(BlueprintPure, BlueprintGetter, Category = "Affectable Object")
	UStaticMesh* GetObjectMesh() const;

	// MUTATORS/SETTERS 
	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Ability Reaction")
	void SetReactionIDValue(int Value);

	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Ability Reaction")
	void SetMaxReactionID(int Value);

	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Ability Reaction")
	void SetIsHiddenInGameValue(bool Value);
	
	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Ability Reaction")
	void SetIsCollisionEnabledValue(bool Value);

	UFUNCTION(BlueprintCallable, BlueprintSetter, Category = "Affectable Object")
	void SetObjectMesh(UStaticMesh* Mesh);

	// Interface function
	virtual void ToggleVisibility(int ID) override;

};
