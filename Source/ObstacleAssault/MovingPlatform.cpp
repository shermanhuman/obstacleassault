// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	MyVector = pathStart;
	UE_LOG(LogTemp, Display, TEXT("Platform created at %s , target %s"), *pathStart.ToString(), *pathEnd.ToString());
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Calculate progress based on movementRate and DeltaTime
	progress += movementRate * DeltaTime;

	// If progress is greater than 1, we've reached the end
	if (progress >= 1.0f)
	{
		// Swap pathStart and pathEnd
		FVector temp = pathStart;
		pathStart = pathEnd;
		pathEnd = temp;

		// Reset progress
		progress = 0.0f;
	}

	// Interpolate between pathStart and pathEnd based on progress
	MyVector = FMath::Lerp(pathStart, pathEnd, progress);

	SetActorLocation(MyVector);
}


