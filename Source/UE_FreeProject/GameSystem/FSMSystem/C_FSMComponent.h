// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_FSMComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE(FStateStartDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FStateUpdateDelegate, float, DeltaTime);
DECLARE_DYNAMIC_DELEGATE(FStateEndDelegate);

/// <summary>
/// 상태 클래스
/// </summary>
UCLASS()
class UE_FREEPROJECT_API UState : public UObject
{
	GENERATED_BODY()

public:
	FStateStartDelegate Start;
	FStateUpdateDelegate Update;
	FStateEndDelegate End;
};

/// <summary>
/// FSM 컴포넌트
/// </summary>
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_FREEPROJECT_API UC_FSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UC_FSMComponent();

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintCallable, Category = "StateComponent")
	void CreateState(const FName& Name, FStateStartDelegate Start, FStateUpdateDelegate Update, FStateEndDelegate End);

	UFUNCTION(BlueprintCallable, Category = "StateComponent")
	void ChangeState(const FName& Name);

	UFUNCTION(BlueprintCallable, Category = "StateComponent")
	FName GetCurrentStateName()
	{
		return CurrentState->GetFName();
	}

private:
	UPROPERTY(VisibleAnywhere)
	TMap<FName, TObjectPtr<UState>> AllState;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UState> CurrentState = nullptr;
			
};
