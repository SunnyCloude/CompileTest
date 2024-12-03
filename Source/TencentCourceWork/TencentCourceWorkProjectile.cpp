// Copyright Epic Games, Inc. All Rights Reserved.

#include "TencentCourceWorkProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "TencentCourceWorkPlayerState.h"
#include "TencentCourceWorkCharacter.h"

ATencentCourceWorkProjectile::ATencentCourceWorkProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ATencentCourceWorkProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void ATencentCourceWorkProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		//给玩家加分
		ATencentCourceWorkCharacter* character = Cast<ATencentCourceWorkCharacter>(GetOwner());
		ATencentCourceWorkPlayerState* playerState = Cast<ATencentCourceWorkPlayerState>(character->GetPlayerState());
		playerState->IncreaseScore();

		//命中物体
		if (!OtherActor->Tags.Contains("Scale"))
		{
			OtherActor->SetActorScale3D(FVector(HitScale));
			OtherActor->Tags.Add("Scale");
		}
		else
		{
			OtherActor->Destroy();
		}

		Destroy();
	}
}