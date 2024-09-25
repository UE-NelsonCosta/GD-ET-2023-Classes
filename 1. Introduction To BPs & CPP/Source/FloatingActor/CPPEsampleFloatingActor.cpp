// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPEsampleFloatingActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACPPEsampleFloatingActor::ACPPEsampleFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("ObjectRoot");
	
	Cube = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	Cube->SetupAttachment(RootComponent);



}

// Called when the game starts or when spawned
void ACPPEsampleFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPEsampleFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!UseBlueprint)
	{
		UpdateRelativeTransform(DeltaTime);
	}

}

void ACPPEsampleFloatingActor::UpdateRelativeTransform(float DeltaTime)
{
		Timer += DeltaTime;
    
    	FVector Temp = FMath::Sin(Timer) * MovementRange;
    
    	if(Cube)
    	{
    		Cube->SetRelativeLocation(Temp);
    	}
}

