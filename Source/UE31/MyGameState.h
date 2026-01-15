// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class UE31_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:	
	AMyGameState();
	virtual void Tick(float DeltaTime) override;

protected:	//設定項目
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyGameState")
	USoundBase* sbMusic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyGameState")
	TSoftObjectPtr<UWorld> sLevel;

public:		//タイマー関連変数

	//制限時間
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyGameState")
	float m_tsTimeLimit;

	//経過時間
	UPROPERTY()
	float m_tsElasped;

	//残り時間
	UPROPERTY()
	float m_tsRemaining;

	UPROPERTY()
	bool m_bTimeUp = false;

public:		//他参照関数

	float GetTimeLimit() const;
	float GetRemainingTime() const;

	bool GetIsTimeUp() const;
};
