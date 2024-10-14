// Copyright (c) 2024 CYBERKOALA LLC

#include "PS_PlayerState.h"
#include "PS_Character.h"
#include "PS_CharacterStats.h"
#include "Net/UnrealNetwork.h"

void APS_PlayerState::OnRep_Xp(int32 OldValue) const
{
	OnXpChanged.Broadcast(Xp);
}

void APS_PlayerState::OnRep_CharacterLevelUp(int32 OldValue) const
{
	OnCharacterLevelUp.Broadcast(CharacterLevel);
}

void APS_PlayerState::AddXp(int32 Value)
{
	Xp += Value;
	OnXpChanged.Broadcast(Xp);
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, FString::Printf(TEXT("Total Xp: %d"), Value));

	if (const auto Character = Cast<APS_Character>(GetPawn()))
	{
		if (Character->GetCharacterStats()->NextLevelXp < Xp)
		{
			GEngine->AddOnScreenDebugMessage(3, 5.f, FColor::Red, TEXT("Level Up!"));
			CharacterLevel++;
			Character->UpdateCharacterStats(CharacterLevel);
			OnCharacterLevelUp.Broadcast(CharacterLevel);
		}
	}
}

void APS_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(APS_PlayerState, Xp, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(APS_PlayerState, CharacterLevel, COND_OwnerOnly);
}
