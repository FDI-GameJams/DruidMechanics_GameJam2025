// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enumerations/EItemType.h"
#include "ItemBase.generated.h"

UCLASS()
class DRUIDMECHANICS_API AItemBase : public AActor
{
	GENERATED_BODY()
	
private:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties")
	USceneComponent* DefaultSceneRoot{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
	UStaticMeshComponent* ItemMesh{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
	TEnumAsByte<EItemType> ItemType{ EItemType::NONE };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
	int ItemQuantity{ 1 };

public:	
	// Sets default values for this actor's properties
	AItemBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
