#include "pch.h"
#include "Monster.h"

Monster::Monster() : Object(ObjectType::Monster)
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
	_Stat.Hp = 100;
	_Stat.maxHp= 100;
	_Stat.Speed = 10;

}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
	Utils::DrawRect(hdc, _pos, 50, 50);
}
