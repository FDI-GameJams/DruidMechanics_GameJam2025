// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityAffectables/AffectableObject.h"

// Sets default values
AAffectableObject::AAffectableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

