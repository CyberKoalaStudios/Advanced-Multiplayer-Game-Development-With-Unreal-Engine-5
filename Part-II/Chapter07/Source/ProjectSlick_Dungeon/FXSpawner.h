// Copyright (c) 2024 CYBERKOALA LLC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FXSpawner.generated.h"

class USphereComponent;

UCLASS(Abstract)
class PROJECTSLICK_DUNGEON_API AFXSpawner : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* _FXSpawnerCollision;

	int _TimesHit;
	
public:	
	// Sets default values for this actor's properties
	AFXSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnFXSpawnerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void ThreeHitVisuals();
};
