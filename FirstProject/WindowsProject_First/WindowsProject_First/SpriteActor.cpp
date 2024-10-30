#include "pch.h"
#include "Spriteactor.h"
#include "Sprite.h"

Spriteactor::Spriteactor()
{
}

Spriteactor::~Spriteactor()
{
}

void Spriteactor::BeginPlay()
{
	Super::BeginPlay();
}

void Spriteactor::Tick()
{
	Super::Tick();
}

void Spriteactor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_sprite == nullptr)
	{
		return;
	}

	VectorInt size = _sprite->GetSize();

	/*::BitBlt(hdc,
		static_cast<int32>(_pos.x) - size.x / 2,
		static_cast<int32>(_pos.y) - size.y / 2,
		size.x,
		size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		SRCCOPY);*/

	::TransparentBlt(
		hdc,
		static_cast<int32>(_pos.x) - size.x / 2,
		static_cast<int32>(_pos.y) - size.y / 2,
		size.x,
		size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		_sprite->GetSize().x,
		_sprite->GetSize().y,
		_sprite->GetTransparent()
		);

}
