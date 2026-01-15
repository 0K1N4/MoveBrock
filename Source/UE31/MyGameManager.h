// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "MyPanel.h"
#include "MyBrock.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyGameManager.generated.h"

/**
 * 
 */
UCLASS()
class UE31_API UMyGameManager : public UObject
{
	GENERATED_BODY()

public:
	UMyGameManager();
	void LocadeStage();
	void clearStage();

private:
	UWorld* m_pWorld;

	UPROPERTY()
	TArray<AMyPanel*> m_pPanels;

	UPROPERTY()
	TArray<AMyBrock*> m_pBrock;

};
