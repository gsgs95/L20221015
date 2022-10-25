// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
// UHT에서 헤더파일 생성시, 파싱룰때문에, 자기 자신보다 아래에 헤더 선언해야함. 아니면 결국 오류남.
// 빌드속도를 빠르게 하기위해, cpp에만 헤더 인클루드 할것임.
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
	//GEngine->AddOnScreenDebugMessage(0, 10.0f, FColor::Red, TEXT("Hello World"));

	// Class Reference : BP에서 클래스의 이름을 기억하는것.
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

