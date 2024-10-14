// Copyright (c) 2024 CYBERKOALA LLC

#include "PS_BasePickup.h"
#include "PS_Character.h"

// Sets default values
APS_BasePickup::APS_BasePickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>("Collision");
	RootComponent = SphereCollision;
	SphereCollision->SetGenerateOverlapEvents(true);
	SphereCollision->SetSphereRadius(200.0f);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(SphereCollision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	bReplicates = true;
}

// Called when the game starts or when spawned
void APS_BasePickup::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &APS_BasePickup::OnBeginOverlap);
}

void APS_BasePickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const auto Character = Cast<APS_Character>(OtherActor))
	{
		Pickup(Character);
	}
}

void APS_BasePickup::Pickup_Implementation(APS_Character* OwningCharacter)
{
	SetOwner(OwningCharacter);
}

// Called every frame
void APS_BasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
