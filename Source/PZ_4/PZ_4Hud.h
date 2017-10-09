// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "PZ_4Hud.generated.h"


UCLASS(config = Game)
class APZ_4Hud : public AHUD
{
	GENERATED_BODY()

public:
	APZ_4Hud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
