// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCPawn.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TEKOPRO_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category="Player")
		void GetName(AActor * actor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int age;


	UFUNCTION(BlueprintCallable)
		void UpdateDialogHUD(ANPCPawn* npc);

	UFUNCTION(BlueprintCallable)
		void EmptyDialogHUD();

	UFUNCTION(BlueprintCallable)
		void NextDialog(int Id);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DialogCase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ANPCPawn* TalkNPC;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DialogTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DialogOpt1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DialogOpt2;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		FString 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DialogUpdated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Money = 1000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MyScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int DealerScore = 0;


};
