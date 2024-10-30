#pragma once
#include "SpriteActor.h"

class Player : public Spriteactor
{
	using Super = Spriteactor;

public:
	Player();
	virtual ~Player() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;
};

