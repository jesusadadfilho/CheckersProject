// Fill out your copyright notice in the Description page of Project Settings.


#include "GameController.h"

// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
	FillWhiteCheckers();
	FillBRownCheckers();
	
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameController::FillWhiteCheckers()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				CreateChecker(i, j, false);
			}
		}
	}
}

void AGameController::FillBRownCheckers()
{
	for (int i = 5; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				CreateChecker(i, j, true);
			}
		}
	}
}

void AGameController::CreateChecker(int i, int j, bool bIsBrown)
{
	AChecker* checker = GetWorld()->SpawnActor<AChecker>(AChecker::StaticClass(), FVector(i * 100, j * 100, 70), FRotator(0, 0, 0));
	checker->SetupCheckerMaterial(bIsBrown);
}

