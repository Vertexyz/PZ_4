// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PZ_4GameMode.h"
#include "TrafficLight.generated.h"

UENUM()
enum StateEnum
{
	Red,
	Yellow,
	Green,
};

UCLASS()
class PZ_4_API ATrafficLight : public AActor
{
	GENERATED_BODY()
	
public:	
	ATrafficLight();

	void SetRedLight();
	void SetYellowLight();
	void SetGreenLight();

	UMaterialInstanceDynamic* GetLighterMaterial();

	FDelegateHandle  LightTriggerHandle;
	FDelegateHandle  ReleaseHandle;

	UPROPERTY()
		FTimerHandle Timer;
	
	UPROPERTY()
		APZ_4GameMode* MyGameMode;

	UPROPERTY()
		TEnumAsByte<StateEnum> CurrentState;

	UPROPERTY(EditAnywhere)
		USceneComponent* Root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* TrafficLightMesh;
	
	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* TrafficLightMaterial;

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	void ToggleLight();
	void ReleaseLight();

private:	
	void SetTrafficLightState(float state);
	
	
};
