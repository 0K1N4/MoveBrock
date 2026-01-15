// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeWidgetController.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameState.h"
#include "TimeWidget.h"

ATimeWidgetController::ATimeWidgetController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATimeWidgetController::BeginPlay()
{
	Super::BeginPlay();
}

void ATimeWidgetController::Tick(float DeltaTime)
{
	

	Super::Tick(DeltaTime);

	AMyGameState* gs = Cast<AMyGameState>(UGameplayStatics::GetGameState(this));


	if (gs)
	{
		m_tsRemaining = gs->GetRemainingTime();

		//時間切れでなければ
		if (gs->GetIsTimeUp() == false)
		{
			UTimeWidget* timeWidget = Cast<UTimeWidget>(m_pStockWidget);
			timeWidget = Cast<UTimeWidget>(m_pStockWidget);
			if (timeWidget)
			{
				//分と秒をローカル変数にそれぞれ格納
				int32 minute = m_tsRemaining / 60;
				int32 Second = FMath::FloorToInt32(m_tsRemaining) % 60;

				//Widgetのテキストにセット
				timeWidget->SetTimeText(minute, Second);
			}
		}
	}
}