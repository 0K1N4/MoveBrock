// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "MyBrock.generated.h"

UCLASS()
class UE31_API AMyBrock : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyBrock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:	//定数
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyBrock", meta = (AllowPrivateAccess = "true"))
	float m_fScaler;

protected:	//変数
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MyBrock")
	FVector m_fvInitPos;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MyBrock")
	bool m_bFinish;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MyBrock")
	bool m_bStop;

public:		//変数
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MyBrock")
	FVector m_fvOldVec;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MyBrock")
	bool m_bMove;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MyBrock")
	bool m_bLock;

protected:	//関数
	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	//操作キャラクターがオブジェクトから見てどの方向にいるのかを把握する関数
	bool GetActorForwardVectorToObj(const APawn* Character);

	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	//オブジェクトの移動量を算出する関数
	float GetMovementAmount(float forwardVec);

	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	//X成分とY成分のどちらが大きかを判断する関数
	bool IsActorBiggerVec(float X, float Y);

	//オブジェクトに移動をさせる関数
	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	void MoveBrock(FVector offset);

	//オブジェクトを初期位置に戻す関数
	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	void ResetBrockPos();

protected:	//ポインタ
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* m_pMoveTarget;

protected:	//set関数
	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	FVector SetInitPos(FVector pos);

	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	void SetBrockFinish(bool finish);

	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	void SetBrockStop(bool stop);

	UFUNCTION(BlueprintCallable, Category = "MyBrock")
	void SetBrockMove(bool move);
};
