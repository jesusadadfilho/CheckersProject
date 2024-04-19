// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Square.generated.h"

struct FSquareData
{
	int32 Row;
	int32 Column;
	bool bIsBlack;
	bool bIsOccupied;
};

UCLASS()
class CHECKERSPROJECT_API ASquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASquare();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FSquareData SquareData;

	UMaterialInterface* whiteMaterial;
	UMaterialInterface* blackMaterial;

	void SetupSquareMaterial();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;



};
