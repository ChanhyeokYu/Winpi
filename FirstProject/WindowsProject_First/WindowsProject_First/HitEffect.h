#pragma once
#include "GameObject.h"

class HitEffect : public GameObject
{
	using Super = GameObject;
public:

	HitEffect();
	virtual ~HitEffect() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:
	virtual void UpdateAnumation() override;
};

