// Fill out your copyright notice in the Description page of Project Settings.

#include "TrafficLight.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "PZ_4GameMode.h"


// Sets default values
ATrafficLight::ATrafficLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	TrafficLightMesh = CreateDefaultSubobject<UStaticMeshComponent>("TrafficLightMesh");
	
	TrafficLightMesh->SetupAttachment(Root);
	
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAssetBody(TEXT("StaticMesh'/Game/Geometry/Meshes/SM_Traffic_Light.SM_Traffic_Light'"));
	if (MeshAssetBody.Object)
	{
		TrafficLightMesh->SetStaticMesh(MeshAssetBody.Object);
	}
}

void ATrafficLight::SetRedLight()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, TEXT("RED"));
	SetTrafficLightState(1.0f);
	
	//GetWorld()->GetTimerManager().SetTimer(Timer, this, &ATrafficLight::SetYellowLight, 3, false);

	CurrentState = Red;
}

void ATrafficLight::SetYellowLight()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, TEXT("YELLOW"));
	SetTrafficLightState(0.5f);

	if(CurrentState == Red)
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &ATrafficLight::SetGreenLight, 1, false);

	if (CurrentState == Green)
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &ATrafficLight::SetRedLight, 1, false);

	CurrentState = Yellow;
}

void ATrafficLight::SetGreenLight()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, TEXT("GREEN"));
	SetTrafficLightState(0.0f);

	//GetWorld()->GetTimerManager().SetTimer(Timer, this, &ATrafficLight::SetYellowLight, 3, false);

	CurrentState = Green;
}

void ATrafficLight::SetTrafficLightState(float state)
{
	GetLighterMaterial()->SetScalarParameterValue(FName("State"), state);
}

UMaterialInstanceDynamic* ATrafficLight::GetLighterMaterial()
{
	if (TrafficLightMaterial == nullptr)
	{
		TrafficLightMaterial = UMaterialInstanceDynamic::Create(TrafficLightMesh->GetMaterial(1), nullptr);
		TrafficLightMesh->SetMaterial(1, TrafficLightMaterial);
	}

	return TrafficLightMaterial;
}

// Called when the game starts or when spawned
void ATrafficLight::BeginPlay()
{
	Super::BeginPlay();

	SetGreenLight();

	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	MyGameMode = Cast<APZ_4GameMode>(StartGameMode);
	if (MyGameMode != nullptr)
	{
		LightTriggerHandle = MyGameMode->CarTriggerDelegate.AddUObject(this, &ATrafficLight::ToggleLight);
		ReleaseHandle = MyGameMode->ReleaseDelegate.AddUObject(this, &ATrafficLight::ReleaseLight);
	}
}

void ATrafficLight::ToggleLight()
{
	SetYellowLight();
}

void ATrafficLight::ReleaseLight()
{
	SetYellowLight();
}
// Called every frame
void ATrafficLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

