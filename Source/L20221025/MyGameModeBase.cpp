// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
// UHT���� ������� ������, �Ľ̷궧����, �ڱ� �ڽź��� �Ʒ��� ��� �����ؾ���. �ƴϸ� �ᱹ ������.
// ����ӵ��� ������ �ϱ�����, cpp���� ��� ��Ŭ��� �Ұ���.
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
	//GEngine->AddOnScreenDebugMessage(0, 10.0f, FColor::Red, TEXT("Hello World"));

	// Class Reference : BP���� Ŭ������ �̸��� ����ϴ°�.
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

