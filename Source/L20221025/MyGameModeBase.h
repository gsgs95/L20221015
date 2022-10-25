// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class L20221025_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameModeBase();

	// ~AMyGameModeBase(); // UE C++ 에서는 소멸자 생성x, 엔진의 가비지 콜렉터가 알아서 UObject 자손클래스 메모리 관리
};
