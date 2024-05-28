// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Board.h>
#include <Checker.h>
#include "GameController.generated.h"

UCLASS()
class CHECKERSPROJECT_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	ABoard* Board;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkers")
	TArray<AChecker*> WhiteCheckers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkers")
	TArray<AChecker*> BrownCheckers;

	UFUNCTION(BlueprintCallable, Category = "Board")
	void FillWhiteCheckers();

	UFUNCTION(BlueprintCallable, Category = "Board")
	void FillBRownCheckers();


	void CreateChecker(int i, int j, bool bIsBrown);
};
