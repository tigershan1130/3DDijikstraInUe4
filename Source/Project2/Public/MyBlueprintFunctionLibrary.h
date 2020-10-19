// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Kismet/KismetMathLibrary.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT2_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Path Planning")
	static void ShortestPath(TArray<FVector> data, int start, float weight, TArray<int>& s, TArray<float>& dist, TArray<int>& path);
};
