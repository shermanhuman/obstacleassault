// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(0,0,0);

	UPROPERTY(EditAnywhere)
	FVector pathStart = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere)
	FVector pathEnd = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere)
	float movementRate = 1;

private:
	float progress = 0.0f; 
};
