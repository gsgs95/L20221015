// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

// 컴포넌트 전방선언
class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;
class UArrowComponent;


UCLASS()
class L20221025_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBoxComponent* Box; // 맴버변수 선언

	UStaticMeshComponent* Body;
	UStaticMeshComponent* Left;
	UStaticMeshComponent* Right;
	
	USpringArmComponent* SpringArm;
	
	UCameraComponent* Camera;
	
	UFloatingPawnMovement* FloatingPawnMovement;

	UArrowComponent* Arrow;


};
