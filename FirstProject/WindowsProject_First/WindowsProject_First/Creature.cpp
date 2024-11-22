#include "pch.h"
#include "Creature.h"
#include "Scene.h"
#include "SceneManager.h"
#include "DevScene.h"

Creature::Creature()
{
}

Creature::~Creature()
{
}

void Creature::BeginPlay()
{
	Super::BeginPlay();
}

void Creature::Tick()
{
	Super::Tick();

}

void Creature::Render(HDC hdc)
{
	Super::Render(hdc);

}

void Creature::OnDamaged(Creature* attacker)
{
	if (attacker == nullptr)
	{
		return;
	}

	Stat& attackerStat = attacker->GetStat();
	Stat& stat = GetStat();

	int32 damage = attackerStat.Attack - stat.Defence;
	if (damage <= 0)
	{
		return;
	}

	stat.Hp = max(0, stat.Hp - damage);
	
	if (stat.Hp == 0)
	{
		Scene* scene = GET_SINGLE(SceneManager)->GetCurrentScene();
		if (scene)
		{
			scene->RemoveActor(this);
		}
	}

}
