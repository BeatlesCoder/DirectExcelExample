// Fill out your copyright notice in the Description page of Project Settings.


#include "ExcelReadTest.h"

#include "DirectExcelLibrary.h"
#include "ExcelStruct.h"
#include "ExcelWorkbook.h"

// Sets default values
AExcelReadTest::AExcelReadTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExcelReadTest::BeginPlay()
{
	Super::BeginPlay();

	UExcelWorkbook* NewWorkbook = UDirectExcelLibrary::LoadExcel(FString("Tables/GameData.xlsx"), ExcelFileRelateiveDir::ProjectContentDir);
	if(NewWorkbook)
	{
		UExcelWorksheet* ActiveSheet = NewWorkbook->SheetAt(0);
		UE_LOG(LogTemp, Display, TEXT("Start Print in C++==================================="));
		ActiveSheet->Print(true);
		UE_LOG(LogTemp, Display, TEXT("End Print in C++==================================="));

		ActiveSheet->SetTableFormat(ExcelTableFormat::TableWithFirstRowColumnHeader);
		int LowestIndex = ActiveSheet->LowestRow() + 1;
		int HighestIndex = ActiveSheet->HighestRow();
		for(int i = LowestIndex; i <= HighestIndex; i++)
		{
			FExcelStruct ExcelStruct;
			UScriptStruct* OutputStruct = FExcelStruct::StaticStruct();
			if(UDirectExcelLibrary::ReadStructAtRowIndexRaw(ActiveSheet, i, OutputStruct, &ExcelStruct))
			{
				UE_LOG(LogTemp, Display, TEXT("Row2 Name:%s, Location:%s, Rotator:%s"), *ExcelStruct.ActorName, *ExcelStruct.Location.ToString(), *ExcelStruct.Rotator.ToString());
				if(ExcelStruct.TraitInfos.Num() > 0)
				{
					UE_LOG(LogTemp, Display, TEXT("TagName:%s, Values:%d"), *ExcelStruct.TraitInfos[0].TagName.ToString(), ExcelStruct.TraitInfos[0].Values[0]);
				}
			}
		}
	}
}

// Called every frame
void AExcelReadTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

