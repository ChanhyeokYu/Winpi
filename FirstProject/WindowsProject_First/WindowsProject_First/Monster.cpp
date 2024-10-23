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

	// ������ ���� ���
	Vector v1 = _end - _start;

	// ���콺�� �ڻ��� �밢 ���
	Vector v2 = mousePos - _start;

	// Ư�� ����� �ִ� ����
	float maxLength = v1.Length();
	// �ش� ���� ����ȭ
	v1.Normalize();

	// ������ ����� �밢 ���
	float dot = v1.Dot(v2);

	Pos pos = _start + v1 * dot;
	
	// ������ �Ѿ�ų� �������� �Ѿ�� �ٷ� �Ŀ��� ������
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
