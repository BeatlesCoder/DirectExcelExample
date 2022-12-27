// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "ExcelStruct.generated.h"

USTRUCT(BlueprintType)
struct FTraitInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName TagName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int> Values;
};

USTRUCT(BlueprintType)
struct DIRECTEXCELEXAMPLE_API FExcelStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ActorName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float LocationZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RotationZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Scale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FRotator Rotator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTraitInfo TraitInfo;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FTraitInfo> TraitInfos;	
	
};
