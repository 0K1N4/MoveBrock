// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeWidget.h"
#include "Components/TextBlock.h"

UTimeWidget::UTimeWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), m_pMinute(nullptr), m_pSecond(nullptr)
{
}

void UTimeWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UTimeWidget::SetTimeText(int32 minute, int32 second)
{
	// •ª‚Æ•b‚ð2Œ…•\Ž¦‚É•ÏŠ·
	FString MinStr = FString::Printf(TEXT("%02d"), minute);
	FString SecStr = FString::Printf(TEXT("%02d"), second);

	if(m_pMinute)
	{
		m_pMinute->SetText(FText::FromString(MinStr));
	}
	if (m_pSecond)
	{
		m_pSecond->SetText(FText::FromString(SecStr));
	}
}