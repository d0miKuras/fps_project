// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileWeapon.generated.h"
class UAction;
class UWeaponData;
class UActionComponent;
UCLASS()
class FPS_PROJECT_API AProjectileWeapon : public AActor {
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category=Gameplay)
	TArray<TSubclassOf<UAction>> mDefaultActions;
	UPROPERTY(EditAnywhere, Category=Visual)
	USkeletalMeshComponent* mWeaponMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Visual)
	FName mMuzzleSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	UActionComponent* mActionComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	UWeaponData* mWeaponData;

public:
	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AProjectileWeapon();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
