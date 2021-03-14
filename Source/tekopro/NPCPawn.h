// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerAttitude.h"
#include "NPCPawn.generated.h"

UCLASS()
class TEKOPRO_API ANPCPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANPCPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanTalk;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CurrentDialogId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Friendliness = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Hostiliness = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Attitude = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MemorySize = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int> ShortMemory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MemoryPointer = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PlayerName = "Unknown";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PlayerIntention = "Unknown";

	UFUNCTION(BlueprintCallable)
		void SetPMemory(int memory);

};
