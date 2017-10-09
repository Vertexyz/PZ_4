// Fill out your copyright notice in the Description page of Project Settings.

#include "Obstacle.h"
#include "ConstructorHelpers.h"
#include "GameFramework/GameModeBase.h"
#include "PZ_4GameMode.h"


// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	//Loading Mesh to Object
	ConstructorHelpers::FObjectFinder<UStaticMesh>LoadedMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (LoadedMesh.Object != nullptr)
	{
		Mesh->SetStaticMesh(LoadedMesh.Object);
	}
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	APZ_4GameMode* MyGameMode = Cast<APZ_4GameMode>(StartGameMode);
	if (MyGameMode != nullptr)
	{
		LightHandle = MyGameMode->CarTriggerDelegate.AddUObject(this, &AObstacle::ToggleObstacle);
		ReleaseHandle = MyGameMode->ReleaseDelegate.AddUObject(this, &AObstacle::RemoveObstacle);
	}
}

void AObstacle::ToggleObstacle()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

void AObstacle::RemoveObstacle()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

