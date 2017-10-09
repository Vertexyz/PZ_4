// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class PZ_4_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	FDelegateHandle  LightHandle;
	FDelegateHandle  ReleaseHandle;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ToggleObstacle();
	void RemoveObstacle();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
