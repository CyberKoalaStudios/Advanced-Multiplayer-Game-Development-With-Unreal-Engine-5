// Copyright (c) 2024 CYBERKOALA LLC


#include "FXSpawner.h"
#include <Components/SphereComponent.h>
#include "PS_Character.h"

// Sets default values
AFXSpawner::AFXSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_FXSpawnerCollision = CreateDefaultSubobject<USphereComponent>(TEXT("TargetCollision"));
	_FXSpawnerCollision->SetupAttachment(RootComponent);
	_FXSpawnerCollision->SetSphereRadius(100.0f, false);
	_FXSpawnerCollision->OnComponentBeginOverlap.AddDynamic(this, &AFXSpawner::OnFXSpawnerBeginOverlap);
	_TimesHit = 0;
}
 
// Called when the game starts or when spawned
void AFXSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFXSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFXSpawner::OnFXSpawnerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
 
	if (OtherActor->IsA(APS_Character::StaticClass()))
	{
		_TimesHit++;
		if (_TimesHit == 3)
		{
			ThreeHitVisuals();
		}
	}
 
}
 