#pragma once
#include "Actor.h"

class Flipbook;

class FlipbookActor : public actor
{
	using Super = actor;
public:
	FlipbookActor();
	virtual ~FlipbookActor();

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	void SetFlipbook(Flipbook* flipbook);
	void Reset();

	bool IsAnimationEnded();

protected:
	Flipbook* _flipbook = nullptr;
	float _sumTime = 0.f;
	int32 _idx = 0;

};

