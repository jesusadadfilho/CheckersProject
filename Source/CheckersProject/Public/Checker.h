// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Checker.generated.h"

UCLASS()
class CHECKERSPROJECT_API AChecker : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChecker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UMaterialInterface* whiteMaterial;
	UMaterialInterface* brownMaterial;


	void SetupCheckerMaterial(bool bIsBrown);

};
