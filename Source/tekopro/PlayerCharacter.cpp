// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	age = 3;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::GetName(AActor * actor) {

}

void APlayerCharacter::UpdateDialogHUD(ANPCPawn* npc) {

	NextDialog(npc->CurrentDialogId);

}

void APlayerCharacter::NextDialog(int Id) {
	switch (Id) {
	case -1:
		DialogCase = "";
		break;
	case 1:
		DialogCase = "Hello stranger, what can I do for you?;What are you selling?;2;What do you know about the dragon?;3;bye;7;";
		break;
	case 2:
		DialogCase = "I mainly sell food. Would you like to buy some?;sure;-1;no thanks;1;";
		break;

	case 3:
		DialogCase = "Dragon? I haven't seen any dragons!;Are you sure?;4;I'm here to kill it!;5;";
		break;

	case 4:
		DialogCase = "If I would have seen it, then I would be gone from here.;Okay;10;bye;7;";
		TalkNPC->Hostiliness += 1;
		break;

	case 5:
		DialogCase = "Really? If that's the case take these.;thanks;6;What are there?;8;";
		TalkNPC->CurrentDialogId = 12;
		break;

	case 6:
		DialogCase = "Now remember the dragon is hot. Be strong!;Thank you, bye;7;";
		break;

	case 7:
		DialogCase = "See you soon!;Continue;-1;";


		break;

	case 8:
		DialogCase = "They will protect you from the Dragon's fire.;Thank you sir;7;";
		break;

	case 10:
		DialogCase = "Is there anything else I can do for you?;You really don't know anything about the dragon?;11;bye;7;";
		break;

	case 11:
		DialogCase = "Now listen you little S***, I don't have any clue about dragons.;Chill bruh;1;I came here to kill it!;5;";
		break;

	case 12:
		DialogCase = "Did you kill the dragon?;Not yet;13;Yes I did;14;Can I see your shop?;-1;";
		break;

	case 13:
		DialogCase = "Well get on with it!;Yes sir!;-1;";
		break;

	case 14:
		DialogCase = "Wonderful. Can I see the dragon's head;I need to go.;-1;";
		break;


	case 20:
		DialogCase = "Hey, could you help me?;Sure;21;Ahhh, No?;22;";
		break;

	case 21:
		DialogCase = "Wonderful! Nice to meet you, my name is Attitude Bot.;Sup, My name is xxTraveler420xx;23;What? My name is Attitude Bot!;22;";
		TalkNPC->Attitude += 0.2;
		break;

	case 22:
		if (TalkNPC->Attitude < 0.8) {
			//DialogUpdated = true;
			DialogCase = "Testing my attitude against you;Okay;20;Wait what?;21;";
			//NextDialog(23);
			return;
		}
		DialogCase = "";
		TalkNPC->Attitude -= 0.1;
		break;

	case 23:
		TalkNPC->PlayerName = "xxTraveler420xx";
		DialogCase = "Wait, I know you! You are the thief!;Umm no;24;...;25;";
		break;


	case 30:
		DialogCase = "Would you like to play a hand?;Yes;31;No;32;";
		break;

	// accepted a game
	case 31:
		if (Money < 20) {
			DialogCase = "Seems like you don't have enough money.;Yeah...;-1;";
			return;
		}

		MyScore = FMath::RandRange(2, 10) + FMath::RandRange(2, 10);
		Money -= 20;

		DialogCase = "";
		DialogCase.Append("Your hand is: ");
		DialogCase.Append(FString::FromInt(MyScore));
		DialogCase.Append(";Hit;33;Stay;34;");

		break;

	// rejected a game
	case 32:
		DialogCase = "";
		break;

	// Hit
	case 33:
		MyScore += FMath::RandRange(2, 10);
		
		if (MyScore == 21) {
			Money += 60;
			DialogCase = "Nice BlackJack!;Cool;30;";
			TalkNPC->SetPMemory(-2);
		}
		else if (MyScore > 21) {
			DialogCase = "Busted! your hand is ";
			DialogCase.Append(FString::FromInt(MyScore));
			DialogCase.Append("; New game; 31; Bye; -1;");
			TalkNPC->SetPMemory(2);
		}
		else if (MyScore < 21) {
			DialogCase = "";
			DialogCase.Append("Your hand is: ");
			DialogCase.Append(FString::FromInt(MyScore));
			DialogCase.Append(";Hit;33;Stay;34;");
		}
		

		break;

	// Stay
	case 34:
		DealerScore = FMath::RandRange(15, 21);

		// win
		if (MyScore > DealerScore) {
			Money += 40;
			DialogCase = "Nice you won! ";
			TalkNPC->SetPMemory(-1);

		}
		// Loss
		else if (MyScore < DealerScore) {
			DialogCase = "Oh no dealer won! ";
			TalkNPC->SetPMemory(1);

		}
		// tie
		else
		{
			Money += 20;
			DialogCase = "Push! ";
			TalkNPC->SetPMemory(0);

		}

		DialogCase.Append(FString::FromInt(MyScore));
		DialogCase.Append(" - ");
		DialogCase.Append(FString::FromInt(DealerScore));
		DialogCase.Append(";New game;31;Bye;-1;");

		break;

	// Busted
	case 35:
		break;

	// Look
	case 36:
		break;



	// Guard
	case 40:
		DialogCase = "Stop! Who are you?;I am a janitor;41;Noone;42;Not your business;43;";
		break;

	// im a janitor
	case 41:
		DialogCase = "Okay. Let me see your id.;(show janitor id);44;I must have lost it;45;";
		break;

	// noone
	case 42:
		DialogCase = "";
		break;

	// not your business
	case 43:
		DialogCase = "";
		break;

	// show id
	case 44:
		TalkNPC->PlayerName = "The Janitor";
		DialogCase = "Are you here for cleaning bunker 66?;What bunker?;46;Yes, yes I am;47;";
		break;

	case 45:
		DialogCase = "";
		break;

	// what bunker
	case 46:
		DialogCase = "Is this your first time here?;Yes;48;What does it look like?;49;";
		break;

	// Cleaningn bunker
	case 47:
		TalkNPC->SetPMemory(1);
		TalkNPC->PlayerIntention = "Cleaning bunker";
		DialogCase = "Have a nice cleaning day, sir!;thanks;-1;**** off;50;";
		break;

	// first day at job
	case 48:
		TalkNPC->SetPMemory(1);
		DialogCase = "";
		break;

	// /s first day at job
	case 49:
		TalkNPC->SetPMemory(-2);
		DialogCase = "";
		break;


	case 50:
		TalkNPC->SetPMemory(-5);
		DialogCase = "...;...;-1;";
		break;



	default:
		break;
	}
}





void APlayerCharacter::EmptyDialogHUD() {
	DialogCase = "";
}

