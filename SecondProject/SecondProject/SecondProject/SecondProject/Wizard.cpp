#include "pch.h"
#include "Wizard.h"

Wizard::Wizard() : Player(PlayerClass::Wizard)
{
	Init();
}

Wizard::~Wizard()
{
}

void Wizard::Init()
{
	stat.maxHp = 100;
	stat.hp = stat.maxHp;
	stat.Attach = 15;
	stat.Armor = 8;
}

void Wizard::Update()
{

}
