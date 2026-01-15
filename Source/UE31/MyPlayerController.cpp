// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ViewWidget(m_uwWidget);
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

template <typename T>
void AMyPlayerController::ViewWidget(TSubclassOf<T> widget)
{
	UUserWidget* thisWidget = CreateWidget<T>(this, widget);
	if (widget == NULL)
	{
		return;
	}
	thisWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	thisWidget->AddToViewport();
	m_pStockWidget= thisWidget;
}