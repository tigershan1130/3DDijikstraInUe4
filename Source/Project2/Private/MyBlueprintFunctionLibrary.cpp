// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::ShortestPath(TArray<FVector> data, int start, float weight, TArray<int>& s, TArray<float>& dist, TArray<int>& path)
{
	float mindis;
	int i, j, k;
	for (i = 0; i < data.Num(); i++)
	{
		s.Add(0);
		if (UKismetMathLibrary::Vector_Distance(data[start], data[i]) == weight) 
		{
			path.Add(start);
			dist.Add(weight);
		}	
		else
		{
			path.Add(-1);
			dist.Add(INFINITY);
		}
	}

	s[start] = 1;

	for (i = 0; i < data.Num(); i++)
	{
		mindis = INFINITY;
		k = start;
		for (j = 0; j < data.Num(); j++)
		{
			if (s[j] == 0 && dist[j] < mindis)
			{
				k = j;
				mindis = dist[j];
			}
		}
		s[k] = 1;
		for (j = 0; j < data.Num(); j++)
		{
			if (s[j] == 0 && UKismetMathLibrary::Vector_Distance(data[k], data[j]) == weight && dist[k] + UKismetMathLibrary::Vector_Distance(data[k], data[j]) < dist[j])
			{
				dist[j] = dist[k] + UKismetMathLibrary::Vector_Distance(data[k], data[j]);
				path[j] = k;
			}
		}
	}
}
