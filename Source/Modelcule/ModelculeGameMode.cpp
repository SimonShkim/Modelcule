// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ModelculeGameMode.h"
#include "ModelculeHUD.h"
#include "ModelculeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AModelculeGameMode::AModelculeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AModelculeHUD::StaticClass();
}
