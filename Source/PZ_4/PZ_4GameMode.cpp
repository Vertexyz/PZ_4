// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PZ_4GameMode.h"
#include "PZ_4Pawn.h"
#include "PZ_4Hud.h"

APZ_4GameMode::APZ_4GameMode()
{
	DefaultPawnClass = APZ_4Pawn::StaticClass();
	HUDClass = APZ_4Hud::StaticClass();
}
