#pragma once
#include "actor.h"

class Sprite;

class Spriteactor : public actor
{
	using Super = actor;

public:
	Spriteactor();
	virtual ~Spriteactor() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	void SetSprite(Sprite* sprite) { _sprite = sprite; }


private:
	Sprite* _sprite = nullptr;

};

