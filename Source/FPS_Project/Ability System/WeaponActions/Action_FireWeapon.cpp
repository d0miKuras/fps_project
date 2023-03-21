// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_FireWeapon.h"
#include "FPS_Project/Weapon/ProjectileWeapon.h"

void UAction_FireWeapon::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);
	auto weapon = Cast<AProjectileWeapon>(Instigator);
	// TODO: cast to weapon, get muzzle socket location, get projectile class, spawn
}
