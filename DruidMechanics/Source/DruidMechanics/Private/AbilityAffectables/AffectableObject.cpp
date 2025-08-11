// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityAffectables/AffectableObject.h"

// Sets default values
AAffectableObject::AAffectableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize default root component
	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Root Component"));
	SetRootComponent(DefaultRootComponent);

	// Initialize static mesh component
	ObjectMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object Mesh Component"));
	ObjectMeshComponent->SetupAttachment(GetRootComponent());

	// Set Mesh of StaticMeshComponent to ObjectMesh (of type static mesh)
	// for some reason, this does not work in Blueprint
	ObjectMeshComponent->SetStaticMesh(ObjectMesh);

	// Initialize state of affectable object
	bIsHiddenInGame = true;
	bIsCollisionEnabled = !bIsHiddenInGame;

	this->SetActorHiddenInGame(bIsHiddenInGame);
	this->SetActorEnableCollision(bIsCollisionEnabled);
}

// Called when the game starts or when spawned
void AAffectableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAffectableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AAffectableObject::GetReactionIDValue() const
{
	return ReactionID;
}

int AAffectableObject::GetMaxReactionID() const
{
	return MaxReactionID;
}

UStaticMesh* AAffectableObject::GetObjectMesh() const
{
	return ObjectMesh;
}

void AAffectableObject::SetReactionIDValue(int Value)
{
	if (Value < 0)
	{
		ReactionID = 0;
		return;
	}

	ReactionID = Value;
}

void AAffectableObject::SetMaxReactionID(int Value)
{
	if (Value < 0)
	{
		MaxReactionID = 0;
		return;
	}

	MaxReactionID = Value;
}

void AAffectableObject::SetIsHiddenInGameValue(bool Value)
{
	bIsHiddenInGame = Value;
}

void AAffectableObject::SetIsCollisionEnabledValue(bool Value)
{
	bIsCollisionEnabled = Value;
}

void AAffectableObject::SetObjectMesh(UStaticMesh* Mesh)
{
	ObjectMesh = Mesh;
}

void AAffectableObject::ToggleVisibility(int ID)
{
	// if it's not affectable object's turn to toggle visibility, return early
	if (ID != ReactionID)
	{
		return;
	}

	this->SetActorHiddenInGame(!bIsHiddenInGame);
	this->SetActorEnableCollision(!bIsCollisionEnabled);
}

