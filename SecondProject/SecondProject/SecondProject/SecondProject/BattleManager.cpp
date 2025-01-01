#include "pch.h"
#include "BattleManager.h"
#include "Object.h"
#include "Player.h"
#include "Wizard.h"
#include "Warrior.h"

void BattleManager::ApplyDamage(Object* subject, Object* target)
{
	target->GetStat().hp -= subject->GetStat().Attack;
}

