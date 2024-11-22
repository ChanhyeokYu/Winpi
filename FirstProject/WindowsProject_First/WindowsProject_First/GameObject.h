#pragma once
#include "FlipbookActor.h"

class GameObject : public FlipbookActor
{
	using Super = FlipbookActor;

public:
	GameObject();
	virtual ~GameObject() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	virtual void TickIdle() {}
	virtual void TickMove() {}
	virtual void TickSkill() {}

public:
	void SetState(ObjectState ObjectState);
	ObjectState GetState() { return _state; }

	void SetDir(Dir dir);

	virtual void UpdateAnumation() abstract;

	bool HasReachedDest();
	bool CanGo(VectorInt cellPos);
	Dir GetLookAtDir(VectorInt cellPos);

	void SetCellPos(VectorInt cellPos, bool teleport = false);
	VectorInt GetCellPos() { return _cellPos; }
	VectorInt GetFrontCellPos();

protected:

	VectorInt _cellPos = {};
	Vector _speed = {};
	Dir _dir = DIR_DOWN;
	ObjectState _state = ObjectState::Idle;
	bool _keyPressed = false;

};

