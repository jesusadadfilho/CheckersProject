#include "Square.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "Square.h"

// Sets default values
ASquare::ASquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh>Square(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	ConstructorHelpers::FObjectFinder<UMaterialInterface>WM(TEXT("/Script/Engine.Material'/Game/Materials/M_WhiteMaterial.M_WhiteMaterial'"));
	ConstructorHelpers::FObjectFinder<UMaterialInterface>BM(TEXT("/Script/Engine.Material'/Game/Materials/M_BlackMaterial.M_BlackMaterial'"));

	if(WM.Succeeded())
		whiteMaterial = WM.Object;
	
	if(BM.Succeeded())
		blackMaterial = BM.Object;
	

	if (Square.Succeeded() && WM.Succeeded()){
		StaticMeshComponent->SetStaticMesh(Square.Object);
		StaticMeshComponent->SetMaterial(0, WM.Object);
	}



}

// Called when the game starts or when spawned
void ASquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASquare::SetupSquareMaterial()
{
	if (SquareData.bIsBlack)
	{
		StaticMeshComponent->SetMaterial(0, blackMaterial);
	}
	else
	{
		StaticMeshComponent->SetMaterial(0, whiteMaterial);
	}
}

