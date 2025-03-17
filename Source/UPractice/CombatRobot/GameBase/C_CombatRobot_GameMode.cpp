// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatRobot/GameBase/C_CombatRobot_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

void AC_CombatRobot_GameMode::BeginPlay()
{
	// 메인 카메라 설정
	if (ACameraActor* MainCamera = GetWorld()->SpawnActor<ACameraActor>(FVector(0.0f, 1000.0f, 50.0f), FRotator(0.0f, -90.0f, 0.0f)))
	{
		if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
		{
			PlayerController->SetViewTargetWithBlend(MainCamera);
		}
	}
}