// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileWeapon.h"

#include "FPS_Project/Ability System/ActionComponent.h"


// Sets default values
AProjectileWeapon::AProjectileWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	mWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	mActionComponent = CreateDefaultSubobject<UActionComponent>(TEXT("Action Component"));
}

void AProjectileWeapon::Fire()
{
}

// Called when the game starts or when spawned
void AProjectileWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

