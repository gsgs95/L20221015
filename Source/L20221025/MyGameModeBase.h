// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 *
 */
UCLASS() // 언리얼 엔진이 관리하는 클래스 선언. 메모리 자동관리
class L20221025_API AMyGameModeBase : public AGameModeBase
{

	GENERATED_BODY() // 해당 코드를 만나면, UE Compiler가 자동으로 코드를 추가 생성해준다. 
		// 컴파일 단계: 1. C++컴파일러가 해당 매크로를 만나면 UHT가 실행되어 코드생성
		// 2. C++ 코드와 합침.
		// 3. C++ 컴파일러가 컴파일.
		// 언리얼 헤더툴이 작동되면서 헤더를 만들어 코드를 생성한다.
		// 즉, generated.h 은 절대 수동으로 건드리는 것이 아니다.
public:
	// CDO 초기화  => 엔진 호출전에 호출된다.  
	// 원본을 만들어 저장해두고, 인스턴스 생성시 해당 원본을 복사해 가져다 쓰도록 아키텍쳐가 구성되어있다.
	// UE CPP에서 생성자는 용도가 다르다!
	// 메모리의 원본 모양 잡을때 사용되는 것이기 때문에, 리소스 로딩은 지양하는 것이 좋다.
	// (엔진 시작하자마자 원본에 큰 용량이 들어가 있기 때문.)
	AMyGameModeBase();

	

	// ~AMyGameModeBase(); // UE C++ 에서는 소멸자 생성x, 엔진의 가비지 콜렉터가 알아서 UObject 자손클래스 메모리 관리
};
// 멀티스레드 자동화
// 포인터 생성, 메모리 삭제 순서, 삭제 자동화
// 시리얼라이즈 자동화

