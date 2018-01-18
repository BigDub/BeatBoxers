// copyright 2017 BYU Animation

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Interfaces/IFighterPlayerState.h"
#include "BBPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BEATBOXERS_API ABBPlayerState : public APlayerState, public IFighterPlayerState
{
	GENERATED_UCLASS_BODY()
	
protected:
	float Special;
	float Health = 100.0f;
	int BeatCombo;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxSpecial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APawn *MyPawn;

	// Begin IFighterPlayerState
	UFUNCTION(BlueprintCallable)
	virtual float GetSpecial() const override;

	UFUNCTION(BlueprintCallable)
	virtual float GetSpecialAsPercent() const override;

	UFUNCTION(BlueprintCallable)
	virtual void AddSpecial(float Amount) override;

	UFUNCTION(BlueprintCallable)
	virtual bool UseSpecial(float Amount) override;
	
	virtual void TakeDamage(float Amount) override;

	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() override;
	// End IFighterPlayerState

	virtual int GetBeatCombo() const override;

	virtual int SetBeatCombo(int Combo) override;
};
