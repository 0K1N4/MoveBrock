// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayerController.h"
#include "TimeWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class UE31_API ATimeWidgetController : public AMyPlayerController
{
	GENERATED_BODY()

public:
	ATimeWidgetController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:	//ƒ|ƒCƒ“ƒ^
	UPROPERTY()
	UUserWidget* m_pTimer;

private:
	float m_tsRemaining;

};
