// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatRobot/GameSystem/SplineSystem/C_CombatRobot_SplinePath.h"

// Sets default values
AC_CombatRobot_SplinePath::AC_CombatRobot_SplinePath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC_CombatRobot_SplinePath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_CombatRobot_SplinePath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

