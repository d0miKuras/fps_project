// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPS_Project/Projectile/Projectile.h"
#include "WeaponData.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PROJECT_API UWeaponData : public UDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectile> Projectile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ClipSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ClipAmount;
};
