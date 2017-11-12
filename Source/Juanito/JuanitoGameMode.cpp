// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "JuanitoGameMode.h"
#include "JuanitoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJuanitoGameMode::AJuanitoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> HumanPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (HumanPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = HumanPawnBPClass.Class;
	}
}

