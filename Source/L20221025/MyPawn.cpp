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

	// (TEXT() UTF-8 �ڵ�� ������ �ִ� ��ũ��)
	// Box��� �̸��� ���� �ڽ�������Ʈ�� �����Ͽ� �־���.
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box")); 
	RootComponent = Box; // RootComponent�� �ڽ��� ��Ʈ�� ����.
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	// Body �� Box�� ����
	Body->SetupAttachment(Box);
	
	// ������� ���� �ӽ÷� ���ҽ��� �����ڿ��� �ҷ���. ������ ���� ū ���ҽ��� �Դ°� �����ϱ� ���� staticŰ���� �־���.(1ȸ�� �۵�)
	// TEXT�ȿ� ���ϴ� ����ƽ�Ž��� ���۷��� ���� �� �ٿ��ֱ�
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT
	("StaticMesh'/Game/P38/MyMeshes/SM_P38_Body.SM_P38_Body'"));
	
	// ã�� �����ߴٸ� Body�� ����ƽ �Ž��� �ش� �Ž� ����.
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

	// ã�� �����ߴٸ� Body�� ����ƽ �Ž��� �ش� �Ž� ����.
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

