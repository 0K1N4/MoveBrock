// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "TimeWidget.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE31_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:	//ポインタ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyGameState")
	TSubclassOf<UUserWidget> m_uwWidget;

	//保存用
	UPROPERTY()
	UUserWidget* m_pStockWidget;

protected:	//関数
	template <typename T>
	void ViewWidget(TSubclassOf<T> Widget);
};
