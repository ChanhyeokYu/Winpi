#include "pch.h"
#include "UI.h"
#include "InputManager.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::BeginPlay()
{
}

void UI::Tick()
{
}

void UI::Render(HDC hdc)
{
}

RECT UI::GetRect()
{
	RECT rect =
	{
		_pos.x - _size.x / 2,
		_pos.y - _size.y / 2,
		_pos.x + _size.x / 2,
		_pos.y + _size.y / 2,

	};

	return rect;
}

bool UI::IsMouseInRect()
{
	RECT rect = GetRect();

	POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

	// 사각형 안에 점이 있는지 판별
	//::PtInRect(&rect, mousePos);

	// 수작업으로 구현
	if (mousePos.x < rect.left)
	{
		return false;
	}
	if (mousePos.x > rect.right)
	{
		return false;
	}
	if (mousePos.y < rect.top)
	{
		return false;
	}
	if (mousePos.y > rect.bottom)
	{
		return false;
	}

}
