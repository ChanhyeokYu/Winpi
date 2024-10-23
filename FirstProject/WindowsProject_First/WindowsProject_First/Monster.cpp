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

}

void Monster::Update()
{
	Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();

	// 정해진 범위 계산
	Vector v1 = _end - _start;

	// 마우스와 코사인 대각 계산
	Vector v2 = mousePos - _start;

	// 특정 경로의 최대 길이
	float maxLength = v1.Length();
	// 해당 범위 정규화
	v1.Normalize();

	// 정해진 경로의 대각 계산
	float dot = v1.Dot(v2);

	Pos pos = _start + v1 * dot;
	
	// 범위르 넘어서거나 시작지를 넘어갈때 바로 식에서 빠지기
	if (dot < 0 || dot > maxLength)
	{
		return;
	}

	_pos = pos;
}

void Monster::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 50);

	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldpen = static_cast<HPEN>(::SelectObject(hdc, static_cast<HGDIOBJ>(pen)));
	{
		Utils::DrawLine(hdc, _start, _end);
	}
	::SelectObject(hdc, oldpen);
	::DeleteObject(pen);
}
