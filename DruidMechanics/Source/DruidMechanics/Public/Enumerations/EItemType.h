// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EItemType.generated.h"

UENUM()
enum EItemType
{
	NONE UMETA(DisplayName = "None"),
	KEY UMETA(DisplayName = "Key"),
	CHARGE UMETA(DisplayName = "Charge")
};
