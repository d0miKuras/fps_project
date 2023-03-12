// Fill out your copyright notice in the Description page of Project Settings.


#include "MentalShot.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"


// Sets default values
AMentalShot::AMentalShot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mCollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	mCollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	mCollisionComp->CanCharacterStepUpOn = ECB_No;
	RootComponent = mCollisionComp;
	mParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particles"));
	mParticleComp->SetupAttachment(mCollisionComp);
	mProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	mProjectileMovementComp->UpdatedComponent = mCollisionComp;
	mProjectileMovementComp->InitialSpeed = 0.f;
	mProjectileMovementComp->MaxSpeed = 0.f;
	mForceComponent = CreateDefaultSubobject<URadialForceComponent>(TEXT("ForceComp"));
	mForceComponent->SetupAttachment(mCollisionComp);
	mForceComponent->RemoveObjectTypeToAffect(EObjectTypeQuery::ObjectTypeQuery1);
	mForceComponent->bIgnoreOwningActor = true;
	mForceComponent->bAutoActivate = false;
	InitialLifeSpan = 0.3f;
}

void AMentalShot::BeginPlay()
{
	Super::BeginPlay();
	mForceComponent->Activate();
}

void AMentalShot::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	mInstigator = GetInstigator();
}
