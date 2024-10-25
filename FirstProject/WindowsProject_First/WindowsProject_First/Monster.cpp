#include "pch.h"
#include "Monster.h"
#include "InputManager.h"

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

	_pos = Pos{ 400,300 };

	_lookPos = Pos{ 550,70 };
	_lookDir = _lookPos - _pos;
	_lookDir.Normalize();

}

void Monster::Update()
{
	
}

void Monster::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 50);

	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldpen = static_cast<HPEN>(::SelectObject(hdc, static_cast<HGDIOBJ>(pen)));
	{
		Utils::DrawLine(hdc, _pos, _lookPos);
	}
	::SelectObject(hdc, oldpen);
	::DeleteObject(pen);

	Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();
	Vector dir = _lookDir;
	dir.Normalize();

	Vector monsterToMouseDir = mousePos - _pos;
	monsterToMouseDir.Normalize();

	float dot = monsterToMouseDir.Dot(dir);
	float rad = ::acos(dot);
	float angle = rad * 180 / 3.14;

	float cross = _lookDir.Cross(monsterToMouseDir);
	if (cross < 0)
	{
		angle = 360 - angle;
	}

	{
		Utils::DrawLine(hdc, _pos, mousePos);
	}

	{
		wstring wstr = std::format(L"angle({0})", angle);
		Utils::DrawTextW(hdc, {20, 50}, wstr);
	}

}
