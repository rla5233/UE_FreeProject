// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "C_CombatRobot_GameMode.generated.h"

UCLASS()
class UPRACTICE_API AC_CombatRobot_GameMode : public AGameMode
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

};
