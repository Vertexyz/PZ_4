// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PZ_4GameMode.generated.h"

DECLARE_MULTICAST_DELEGATE(FCarTriggerDelegate)
DECLARE_MULTICAST_DELEGATE(FReleaseDelegate)

UCLASS()
class APZ_4GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APZ_4GameMode();

	FCarTriggerDelegate CarTriggerDelegate;
	FReleaseDelegate ReleaseDelegate;
};



