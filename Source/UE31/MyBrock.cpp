// Fill out your copyright notice in the Description page of Project Settings.
#include "MyBrock.h"

// Sets default values
AMyBrock::AMyBrock()
	: m_fvInitPos(FVector::ZeroVector), m_bFinish(false), m_bStop(false)
	, m_bMove(false), m_bLock(false), m_pMoveTarget(nullptr), m_fScaler(5.5f)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyBrock::BeginPlay()
{
	Super::BeginPlay();
	SetInitPos(m_pMoveTarget->GetComponentLocation());
}

// Called every frame
void AMyBrock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//操作キャラクターがオブジェクトから見てどの方向にいるかを把握する関数
bool AMyBrock::GetActorForwardVectorToObj(const APawn* character)
{
	FVector distance = GetActorLocation() - character->GetActorLocation();
	//キャラクターの前方ベクトルとオブジェクトとの距離ベクトルの内積を算出
	//内積が正:キャラクターはオブジェクトの前方にいる 内積が負:キャラクターはオブジェクトの後方にいる
	float Vec = FVector::DotProduct(distance, character->GetActorForwardVector());
	return Vec > 0.0f;
}

//オブジェクトの移動量を算出する関数
float AMyBrock::GetMovementAmount(float forwardVec)
{
	//正負を維持したまま絶対値を掛ける
	float amount = forwardVec / FMath::Abs(forwardVec) * m_fScaler;
	return amount;
}

//縦方向への移動か横方向への移動かを判定する関数
bool AMyBrock::IsActorBiggerVec(float X, float Y)
{
	//X成分とY成分のどちらが大きかを判定する
	return FMath::Pow(X, 2.0f) > FMath::Pow(Y, 2.0f); 
}

void AMyBrock::MoveBrock(FVector offset)
{
	if (!m_bStop)
	{
		m_pMoveTarget->AddWorldOffset(offset);
		SetBrockFinish(false);
	}
}

void AMyBrock::ResetBrockPos()
{
	SetBrockFinish(m_bFinish);
	if (!m_bStop)
	{
		m_pMoveTarget->SetWorldLocation(m_fvInitPos, false, nullptr, ETeleportType::TeleportPhysics);
	}
	SetBrockStop(false);
	SetBrockMove(false);
}

FVector AMyBrock::SetInitPos(FVector pos)
{
	m_fvInitPos = pos;
	return m_fvInitPos;
}

void AMyBrock::SetBrockFinish(bool finish)
{ 
	m_bFinish = finish;
}

void AMyBrock::SetBrockStop(bool stop)
{ 
	m_bStop = stop;
}

void AMyBrock::SetBrockMove(bool move)
{ 
	m_bMove = move; 
}