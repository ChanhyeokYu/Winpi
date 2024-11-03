#include "pch.h"
#include "Warrior.h"

Warrior::Warrior() : Player(PlayerClass::Warrior)
{
	Init();
}

Warrior::~Warrior()
{
}

void Warrior::Init()
{
	stat.maxHp = 150;
	stat.hp = stat.maxHp;
	stat.Attach = 8;
	stat.Armor = 15;

}

void Warrior::Update()
{

}
