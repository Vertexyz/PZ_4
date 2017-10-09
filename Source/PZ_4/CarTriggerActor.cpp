// Fill out your copyright notice in the Description page of Project Settings.

#include "CarTriggerActor.h"
#include "Engine/Engine.h"
#include "PZ_4GameMode.h"
#include "TimerManager.h"


// Sets default values
ACarTriggerActor::ACarTriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>("RootTrigger");
	TriggerZone->SetBoxExtent(FVector(20, 10, 5), false);
}

// Called when the game starts or when spawned
void ACarTriggerActor::BeginPlay()
{
	Super::BeginPlay();
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	MyGameMode = Cast<APZ_4GameMode>(StartGameMode);
}

void ACarTriggerActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, *(OtherActor->GetName()));
	
	if (MyGameMode != nullptr)
	{
		MyGameMode->CarTriggerDelegate.Broadcast();
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &ACarTriggerActor::ReleaseLight, 3, false);
	}
}

void ACarTriggerActor::NotifyActorEndOverlap(AActor* OtherActor)
{
}

void ACarTriggerActor::ReleaseLight()
{
	MyGameMode->ReleaseDelegate.Broadcast();
}
// Called every frame
void ACarTriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

