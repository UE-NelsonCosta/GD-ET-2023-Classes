// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHealthComponent.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UCPPHealthComponent::UCPPHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UCPPHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	NormalizedHealth = UKismetMathLibrary::SafeDivide(CurrentHealth, MaxHealth);
}

void UCPPHealthComponent::ModifyHealth(float Modifier)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + Modifier, 0.0f, MaxHealth);
	NormalizedHealth = UKismetMathLibrary::SafeDivide(CurrentHealth, MaxHealth);

	OnHealthChanged.Broadcast(NormalizedHealth);
}

