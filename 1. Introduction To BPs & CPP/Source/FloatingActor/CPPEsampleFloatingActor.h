// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPEsampleFloatingActor.generated.h"

UCLASS()
class FLOATINGACTOR_API ACPPEsampleFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPEsampleFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	float Timer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Object Movement", meta=(AllowPrivateAccess))
	FVector MovementRange = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseBlueprint = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Cube = nullptr;

	UFUNCTION(BlueprintCallable)
	void UpdateRelativeTransform(float DeltaTime);

};
