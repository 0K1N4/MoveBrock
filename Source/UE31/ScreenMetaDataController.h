// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayerController.h"
#include "ScreenMetaDataController.generated.h"

/**
 * 
 */
UCLASS()
class UE31_API AScreenMetaDataController : public AMyPlayerController
{
	GENERATED_BODY()
	
public:
	AScreenMetaDataController();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyGameState")
	USoundBase* sbMusic;

};
