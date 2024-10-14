// Copyright (c) 2024 CYBERKOALA LLC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PS_Character.h"
#include "Components/SphereComponent.h"
#include "PS_BasePickup.generated.h"

class APS_Character;
UCLASS()
class PROJECTSLICK_DUNGEON_API APS_BasePickup : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> SphereCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> Mesh;

public:
	// Sets default values for this actor's properties
	APS_BasePickup();

	FORCEINLINE USphereComponent*	  GetSphereCollision() const { return SphereCollision; }
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return Mesh; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Pickup", meta = (DisplayName = "Pickup"))
	void Pickup(class APS_Character* OwningCharacter);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
