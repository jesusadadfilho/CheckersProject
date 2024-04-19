// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Square.h"
#include "Board.generated.h"

UCLASS()
class CHECKERSPROJECT_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, category="Setup")
	void SetupBoard();

	UFUNCTION(BlueprintCallable, category = "Possibilities")
	TArray<ASquare*> GetPossibleMoves(ASquare* Square);

	UFUNCTION(BlueprintCallable, category = "Possibilities")
	TArray<ASquare*> GetSquaresByRowIndex(int32 rowIndex);

	TArray<TArray<ASquare*>> Squares;

	UPROPERTY(VisibleAnywhere)
	int32 BoardSquare = 8;

};
