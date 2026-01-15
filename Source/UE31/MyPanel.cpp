// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPanel.h"

// Sets default values
AMyPanel::AMyPanel()
	: m_fDistanceValue(170.0f), m_fvOldVec(FVector::ZeroVector),m_fAddValue(80.0f)
	, m_pPanel(nullptr), m_pBrock(nullptr)
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_pBrock = Cast<AMyBrock>(UGameplayStatics::GetActorOfClass(GetWorld(), AMyBrock::StaticClass()));
}

// Called when the game starts or when spawned
void AMyPanel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(m_pBrock->m_bMove)
	{
		//縦方向且つベクトルが右から中心へ向かう時
		if (m_pBrock->m_fvOldVec.X > 0.0f)	
		{
			switch (m_eCollisionTypeX)
			{
			case CollisionTypeX::XCOLLISION:
				TrtansformLocationX(m_fAddValue);
				break;

			case CollisionTypeX::BOTH_XCOLLISION:
				if (Distance() <= m_fDistanceValue)
				{
					TrtansformLocationX(m_fAddValue);
				}
				break;
			default:
				break;
			}
		}
		//縦方向且つベクトルが左から中心へ向かう時
		else if(m_pBrock->m_fvOldVec.X < 0.0f)
		{
			switch (m_eCollisionTypeX)
			{
			case CollisionTypeX::INV_XCOLLISION:
				TrtansformLocationX(-m_fAddValue);
				break;

			case CollisionTypeX::BOTH_XCOLLISION:
				if (Distance() <= m_fDistanceValue)
				{
					TrtansformLocationX(-m_fAddValue);
				}
				break;
			default:
				break;
			}
		}
		//横方向且つベクトルが前から中心へ向かう時
		if (m_pBrock->m_fvOldVec.Y > 0.0f)
		{
			switch (m_eCollisionTypeY)
			{
			case CollisionTypeY::YCOLLISION:
				TrtansformLocationY(m_fAddValue);
				break;
			case CollisionTypeY::BOTH_YCOLLISION:
				if (Distance() <= m_fDistanceValue)
				{
					TrtansformLocationY(m_fAddValue);
				}
				break;
			default:
				break;
			}
		}
		//横方向且つベクトルが後ろから中心へ向かう時
		else if (m_pBrock->m_fvOldVec.Y < 0.0f)
		{
			switch (m_eCollisionTypeY)
			{
			case CollisionTypeY::INV_YCOLLISION:
				TrtansformLocationY(-m_fAddValue);
				break;
			case CollisionTypeY::BOTH_YCOLLISION:
				if (Distance() <= m_fDistanceValue)
				{
					TrtansformLocationY(-m_fAddValue);
				}
				break;
			default:
				break;
			}
		}
	}
}


float AMyPanel::Distance()
{
	float distance = abs(this->GetActorLocation().X - m_pBrock->GetActorLocation().X);
	return distance;
}

void AMyPanel::TrtansformLocationX(float value)
{
	FVector vec;
	vec.X = this->GetActorLocation().X + value;
	vec.Y = this->GetActorLocation().Y;
	vec.Z = this->GetActorLocation().Z;
	m_pBrock->GetRootComponent()->SetWorldLocation(vec);
}

void AMyPanel::TrtansformLocationY(float value)
{
	FVector vec;
	vec.X = this->GetActorLocation().X;
	vec.Y = this->GetActorLocation().Y + value;
	vec.Z = this->GetActorLocation().Z;
	m_pBrock->GetRootComponent()->SetWorldLocation(vec);
}
