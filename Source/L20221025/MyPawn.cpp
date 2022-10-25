// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/StaticMesh.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// (TEXT() UTF-8 코드로 변경해 주는 매크로)
	// Box라는 이름을 가진 박스컴포넌트를 생성하여 넣어줌.
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box")); 
	RootComponent = Box; // RootComponent에 박스를 루트로 만듬.
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	// Body 를 Box에 붙임
	Body->SetupAttachment(Box);
	
	// 디버깅을 위해 임시로 리소스를 생성자에서 불러옴. 생성자 마다 큰 리소스를 먹는걸 방지하기 위해 static키워드 넣어줌.(1회만 작동)
	// TEXT안에 원하는 스태틱매쉬의 레퍼런스 복사 후 붙여넣기
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT
	("StaticMesh'/Game/P38/MyMeshes/SM_P38_Body.SM_P38_Body'"));
	
	// 찾기 성공했다면 Body의 스태틱 매쉬에 해당 매쉬 세팅.
	if (SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}



	Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left"));
	Left->SetupAttachment(Body);


	Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right"));
	Right->SetupAttachment(Body);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Propeller(TEXT
	("StaticMesh'/Game/P38/MyMeshes/SM_P38_Propeller.SM_P38_Propeller'"));

	// 찾기 성공했다면 Body의 스태틱 매쉬에 해당 매쉬 세팅.
	if (SM_Propeller.Succeeded())
	{
		Left->SetStaticMesh(SM_Propeller.Object);
		Right->SetStaticMesh(SM_Propeller.Object);
		Left->SetRelativeLocation(FVector(36.26f, -21.02f, 0.31f));
		Right->SetRelativeLocation(FVector(36.26f, 21.02f, 0.31f));

	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);
	SpringArm->TargetArmLength = 150.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bEnableCameraRotationLag = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->SetRelativeLocation(FVector(0, 0, 20.f));

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);
	Arrow->SetRelativeLocation(FVector(80.f, 0, 0));

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	FloatingPawnMovement->MaxSpeed = 100.0f;
}


// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Left->AddLocalRotation(FRotator(0, 0, 3600.0f * DeltaTime));
	Right->AddLocalRotation(FRotator(0, 0, 3600.0f * DeltaTime));
	
	//AddActorLocalOffset(FVector(100.f * DeltaTime, 0, 0));
	AddMovementInput(GetActorForwardVector());
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

