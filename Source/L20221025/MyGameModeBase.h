// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 *
 */
UCLASS() // �𸮾� ������ �����ϴ� Ŭ���� ����. �޸� �ڵ�����
class L20221025_API AMyGameModeBase : public AGameModeBase
{

	GENERATED_BODY() // �ش� �ڵ带 ������, UE Compiler�� �ڵ����� �ڵ带 �߰� �������ش�. 
		// ������ �ܰ�: 1. C++�����Ϸ��� �ش� ��ũ�θ� ������ UHT�� ����Ǿ� �ڵ����
		// 2. C++ �ڵ�� ��ħ.
		// 3. C++ �����Ϸ��� ������.
		// �𸮾� ������� �۵��Ǹ鼭 ����� ����� �ڵ带 �����Ѵ�.
		// ��, generated.h �� ���� �������� �ǵ帮�� ���� �ƴϴ�.
public:
	// CDO �ʱ�ȭ  => ���� ȣ������ ȣ��ȴ�.  
	// ������ ����� �����صΰ�, �ν��Ͻ� ������ �ش� ������ ������ ������ ������ ��Ű���İ� �����Ǿ��ִ�.
	// UE CPP���� �����ڴ� �뵵�� �ٸ���!
	// �޸��� ���� ��� ������ ���Ǵ� ���̱� ������, ���ҽ� �ε��� �����ϴ� ���� ����.
	// (���� �������ڸ��� ������ ū �뷮�� �� �ֱ� ����.)
	AMyGameModeBase();

	

	// ~AMyGameModeBase(); // UE C++ ������ �Ҹ��� ����x, ������ ������ �ݷ��Ͱ� �˾Ƽ� UObject �ڼ�Ŭ���� �޸� ����
};
// ��Ƽ������ �ڵ�ȭ
// ������ ����, �޸� ���� ����, ���� �ڵ�ȭ
// �ø�������� �ڵ�ȭ

