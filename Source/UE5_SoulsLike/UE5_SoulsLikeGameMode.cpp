// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_SoulsLikeGameMode.h"
#include "UE5_SoulsLikeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_SoulsLikeGameMode::AUE5_SoulsLikeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
