// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MyBrock.h"
#include "MyPanel.generated.h"

UENUM()
enum class CollisionTypeX
{
	XCOLLISION UMETA(DisplayName = "XCollision"),
	INV_XCOLLISION UMETA(DisplayName = "Inv_XCollision"),
	BOTH_XCOLLISION UMETA(DisplayName = "Both_XCollision"),
	NONE_XCOLLISION	UMETA(DisplayName = "None_XCollision")
};

UENUM()
enum class CollisionTypeY
{
	YCOLLISION UMETA(DisplayName = "YCollision"),
	INV_YCOLLISION UMETA(DisplayName = "Inv_YCollision"),
	BOTH_YCOLLISION UMETA(DisplayName = "Both_YCollision"),
	NONE_YCOLLISION	UMETA(DisplayName = "None_YCollision")
};

UCLASS()
class UE31_API AMyPanel : public AActor
{

	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyPanel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:	//定数
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyBrock", meta = (AllowPrivateAccess = "true"))
	float m_fDistanceValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyBrock", meta = (AllowPrivateAccess = "true"))
	float m_fAddValue;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyBrock")
	CollisionTypeX m_eCollisionTypeX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyBrock")
	CollisionTypeY m_eCollisionTypeY;

protected:	//変数
	//単位ベクトル
	UPROPERTY()
	FVector m_fvOldVec;		

	UPROPERTY()
	float m_fDistance;

protected:	//ポインタ
	UPROPERTY()
	UStaticMeshComponent* m_pPanel;

	UPROPERTY()
	AMyBrock* m_pBrock;

protected:	//関数
	UFUNCTION(BlueprintCallable, Category = "MyPanel")
	float Distance();

	UFUNCTION(BlueprintCallable, Category = "MyPanel")
	void TrtansformLocationX(float value);

	UFUNCTION(BlueprintCallable, Category = "MyPanel")
	void TrtansformLocationY(float value);
};
