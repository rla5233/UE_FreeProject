// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSystem/FSMSystem/C_FSMComponent.h"

UC_FSMComponent::UC_FSMComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

/// <summary>
/// 업데이트 함수
/// </summary>
void UC_FSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentState && CurrentState->Update.IsBound())
		CurrentState->Update.Execute(DeltaTime);
}

/// <summary>
/// State 생성 함수
/// </summary>
void UC_FSMComponent::CreateState(const FName& Name, FStateStartDelegate Start, FStateUpdateDelegate Update, FStateEndDelegate End)
{
	if (!AllState.Contains(Name))
	{
		AllState.Add(Name, NewObject<UState>(this, Name));

		AllState[Name]->Start = Start;
		AllState[Name]->Update = Update;
		AllState[Name]->End = End;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%S(%u) > State already exists"), __FUNCTION__, __LINE__);
	}
}

/// <summary>
/// State 변경 함수
/// </summary>
void UC_FSMComponent::ChangeState(const FName& Name)
{
	if (AllState.Contains(Name))
	{
		if (CurrentState != AllState[Name])
		{
			if (CurrentState && CurrentState->End.IsBound())
				CurrentState->End.Execute();

			CurrentState = AllState[Name];

			if (CurrentState->Start.IsBound())
				CurrentState->Start.Execute();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%S(%u) > State not exists"), __FUNCTION__, __LINE__);
	}
}
