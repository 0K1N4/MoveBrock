// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned

AMyGameState::AMyGameState()
{
	PrimaryActorTick.bCanEverTick = true;
	m_tsElasped = 0.0f;
	m_tsRemaining = m_tsTimeLimit;
	m_bTimeUp = false;
}

void AMyGameState::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	UGameplayStatics::PlaySound2D(GetWorld(), sbMusic);
}

// Called every frame
void AMyGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_tsElasped += DeltaTime;

	//ŽžŠÔØ‚ê”»’è
	if(m_tsElasped > m_tsTimeLimit)
	{
		UGameplayStatics::OpenLevel(this, sLevel->GetFName());
		m_bTimeUp = true;
	}
	else
	{
		m_tsRemaining = m_tsTimeLimit - m_tsElasped;
	}
}

float AMyGameState::GetTimeLimit() const
{
	return m_tsTimeLimit;
}

float AMyGameState::GetRemainingTime() const
{
	return m_tsRemaining;
}

bool AMyGameState::GetIsTimeUp() const
{ 
	return m_bTimeUp; 
}