// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPPHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NormalizedHealth);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FLOATINGACTOR_API UCPPHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPPHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	void ModifyHealth(float Modifier);

	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	
protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHealth = 100.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CurrentHealth = 10.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NormalizedHealth = 1.0f;

	
	
};
