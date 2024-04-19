// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"

// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	SetupBoard();
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoard::SetupBoard()
{
	Squares = TArray<TArray<ASquare*>>();
	
	for(int32 i = 0; i < BoardSquare; i++)
	{
		TArray<ASquare*> line;
		for(int32 j = 0; j < BoardSquare; j++)
		{
			ASquare* newSquare = GetWorld()->SpawnActor<ASquare>(ASquare::StaticClass(), FVector(0, 0, 0), FRotator(0, 0, 0));
			FSquareData squareData = FSquareData();
			squareData.Row = i;
			squareData.Column = j;
			squareData.bIsBlack = (i + j) % 2 == 0;
			newSquare->SquareData = squareData;
			newSquare->SetActorLocation(FVector(i * 100 , j * 100 , 0));
			newSquare->SetupSquareMaterial();
			line.Add(newSquare);
		}
		Squares.Add(line);
	}

	for(ASquare* s : Squares[0])
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Squares size %d"), s->SquareData.Column));
	}
}

TArray<ASquare*> ABoard::GetPossibleMoves(ASquare* Square)
{
	TArray<ASquare*> possibleMoves = TArray<ASquare*>();
	if (Square->SquareData.Row - 1 > 0 ) {
		if (Square->SquareData.Column + 1 <= BoardSquare - 1) {
			possibleMoves.Add(Squares[Square->SquareData.Row - 1][Square->SquareData.Column + 1]);
		}

		if (Square->SquareData.Column >= 0) {
			possibleMoves.Add(Squares[Square->SquareData.Row - 1][Square->SquareData.Column]);
		}
	}

	if (Square->SquareData.Row + 1 <= BoardSquare  - 1) {
		if (Square->SquareData.Column + 1 <= BoardSquare - 1) {
			possibleMoves.Add(Squares[Square->SquareData.Row + 1][Square->SquareData.Column + 1]);
		}

		if (Square->SquareData.Column >= 0) {
			possibleMoves.Add(Squares[Square->SquareData.Row + 1][Square->SquareData.Column]);
		}
	}
	
	return possibleMoves;
}

TArray<ASquare*> ABoard::GetSquaresByRowIndex(int32 rowIndex)
{
	return Squares[rowIndex];
}

