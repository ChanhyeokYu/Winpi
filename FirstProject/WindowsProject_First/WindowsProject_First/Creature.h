#pragma once
#include "GameObject.h"

class Creature : public GameObject
{
	using Super = GameObject;

public:
	Creature();
	virtual ~Creature() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	virtual void TickIdle() override {}
	virtual void TickMove() override {}
	virtual void TickSkill() override {}

	virtual void UpdateAnumation() override {}

	virtual void OnDamaged(Creature* attacker);

	void SetStat(Stat Stat) { _Stat = Stat; }
	Stat& GetStat() { return _Stat; }

protected:
	Stat _Stat;

};

