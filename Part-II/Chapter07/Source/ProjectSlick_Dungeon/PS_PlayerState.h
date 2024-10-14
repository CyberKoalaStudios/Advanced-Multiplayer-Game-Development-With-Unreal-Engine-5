// Copyright (c) 2024 CYBERKOALA LLC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PS_PlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnXpChanged, int32, NewXp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterLevelUp, int32, NewLevelXp);

/**
 * 
 */
UCLASS()
class PROJECTSLICK_DUNGEON_API APS_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, ReplicatedUsing = "OnRep_Xp", Category = "Experience")
	int Xp = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, ReplicatedUsing = "OnRep_CharacterLevelUp", Category = "Experience")
	int CharacterLevel = 1;

	UFUNCTION()
	void OnRep_Xp(int32 OldValue) const;

	UFUNCTION()
	void OnRep_CharacterLevelUp(int32 OldValue) const;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnXpChanged OnXpChanged;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnCharacterLevelUp OnCharacterLevelUp;

public:
	UFUNCTION(BlueprintCallable, Category = "Experience")
	void AddXp(int32 Value);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
