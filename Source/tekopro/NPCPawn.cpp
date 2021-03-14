// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCPawn.h"

// Sets default values
ANPCPawn::ANPCPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CanTalk = true;
	CurrentDialogId = -1;

	ShortMemory.Init(0, MemorySize);

}

// Called when the game starts or when spawned
void ANPCPawn::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ANPCPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// -1 hostile; 0 neutral; 1 positive
void ANPCPawn::SetPMemory(int memory) {
	if (MemoryPointer > MemorySize - 1) {
		MemoryPointer = 0;
	}

	ShortMemory[MemoryPointer] = memory;
	MemoryPointer++;
}

