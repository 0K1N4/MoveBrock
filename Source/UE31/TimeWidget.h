// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimeWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE31_API UTimeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UTimeWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* m_pMinute;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* m_pSecond;

public:
	void SetTimeText(int32 minute,int32 Second);
	
};
