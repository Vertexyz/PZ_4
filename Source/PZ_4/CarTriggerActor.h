// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PZ_4GameMode.h"
#include "CarTriggerActor.generated.h"

UCLASS()
class PZ_4_API ACarTriggerActor : public AActor
{
GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere)
	UBoxComponent* TriggerZone;

	UPROPERTY()
	APZ_4GameMode* MyGameMode;

	UPROPERTY()
	FTimerHandle Timer;

	ACarTriggerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;

	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor)override;
	void ReleaseLight();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
