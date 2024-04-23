// Fill out your copyright notice in the Description page of Project Settings.


#include "Checker.h"

// Sets default values
AChecker::AChecker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh>Checker(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	ConstructorHelpers::FObjectFinder<UMaterialInterface>CheckerMaterial(TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Materials/M_Brown_MI.M_Brown_MI'"));
	ConstructorHelpers::FObjectFinder<UMaterialInterface>CheckerWhiteMaterial(TEXT("/Script/Engine.Material'/Game/Materials/M_WhiteMaterial.M_WhiteMaterial'"));

	if (Checker.Succeeded() && CheckerMaterial.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(Checker.Object);
		StaticMeshComponent->SetMaterial(0, CheckerMaterial.Object);
		brownMaterial = CheckerMaterial.Object;
	}

	if (CheckerWhiteMaterial.Succeeded())
	{
		whiteMaterial = CheckerWhiteMaterial.Object;
	}

	StaticMeshComponent->SetRelativeScale3D(FVector(0.8f, 0.8f, 0.1f));

}

// Called when the game starts or when spawned
void AChecker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChecker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChecker::SetupCheckerMaterial(bool bIsBrown)
{
	if (bIsBrown)
	{
		StaticMeshComponent->SetMaterial(0, brownMaterial);
	}
	else
	{
		StaticMeshComponent->SetMaterial(0, whiteMaterial);
	}
}

