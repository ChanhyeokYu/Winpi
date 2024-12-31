#include "pch.h"
#include "BattleManager.h"
#include "Object.h"
#include "Player.h"
#include "Wizard.h"
#include "Warrior.h"

void BattleManager::ApplyDamage(Object& subject, Object& target)
{

}

void BattleManager::test()
{
	Wizard* wizard = new Wizard();
	Warrior* warrior = new Warrior();

	ApplyDamage(*warrior, *wizard);

}
