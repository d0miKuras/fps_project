// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	mCollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Component"));
	mCollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0));
	mCollisionComp->CanCharacterStepUpOn = ECB_No;
	RootComponent = mCollisionComp;
	mProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	mProjectileMovement->UpdatedComponent = mCollisionComp;
	mParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particles"));
	mParticles->SetupAttachment(mCollisionComp);
}