// Copyright (c) 2024 CYBERKOALA LLC

#include "PS_GameMode.h"
#include "PS_PlayerController.h"
#include "PS_PlayerState.h"
#include "PS_Character.h"
#include "UObject/ConstructorHelpers.h"
#include "PS_GameState.h"

APS_GameMode::APS_GameMode()
{
	GameStateClass = APS_GameState::StaticClass();

	PlayerStateClass = APS_PlayerState::StaticClass();
	PlayerControllerClass = APS_PlayerController::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ProjectSlick/Characters/BP_Character"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
