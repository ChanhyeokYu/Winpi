#pragma once
#include "Projectile.h"

class Arrow : public Projectile
{
	using Super = Projectile;

public:
	Arrow();
	virtual ~Arrow() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

protected:
	virtual void TickIdle() override;
	virtual void TickMove() override;
	virtual void TickSkill() override {}

	virtual void UpdateAnumation() override;

private:
	Flipbook* _flipbookMove[4] = {};

};

