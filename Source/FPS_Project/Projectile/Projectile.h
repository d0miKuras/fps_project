// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
UCLASS()
class FPS_PROJECT_API AProjectile : public AActor {
	GENERATED_BODY()
// TODO: collisions
private:
	UPROPERTY(EditAnywhere)
	USphereComponent* mCollisionComp;
	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* mParticles;
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* mProjectileMovement;

public:
	// Sets default values for this actor's properties
	AProjectile();
};
