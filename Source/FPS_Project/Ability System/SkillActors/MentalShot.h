// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MentalShot.generated.h"

class URadialForceComponent;
class UProjectileMovementComponent;
class USphereComponent;
UCLASS()
class FPS_PROJECT_API AMentalShot : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category=Projectile)
	USphereComponent* mCollisionComp;

	UPROPERTY(VisibleAnywhere, Category=Projectile)
	UParticleSystemComponent* mParticleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement)
	UProjectileMovementComponent* mProjectileMovementComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Projectile)
	URadialForceComponent* mForceComponent;

	UPROPERTY()
	AActor* mInstigator;

public:
	// Sets default values for this actor's properties
	AMentalShot();
	FORCEINLINE USphereComponent* GetCollisionComp() const { return mCollisionComp; }
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovementComp() const { return mProjectileMovementComp; }

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
};
