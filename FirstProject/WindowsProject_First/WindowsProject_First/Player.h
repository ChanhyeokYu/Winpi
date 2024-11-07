#pragma once
#include "FlipbookActor.h"

class Flipbook;
class Collider;
class BoxCollider;

enum class PlayerState
{
	Idle,
	Move,
	Jump,
	Skill,
};

class Player : public FlipbookActor
{
	using Super = FlipbookActor;

public:
	Player();
	virtual ~Player() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	//캐릭터 콜리전
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);

private:

	virtual void TickIdle();
	virtual void TickMove();
	virtual void TickSkill();

	void SetState(PlayerState playerState);
	PlayerState GetState() { return _state; }

	void SetDir(Dir dir);

	void UpdateAnumation();
	
	bool HasReachedDest();
	bool CanGo(VectorInt cellPos);
	void SetCellPos(VectorInt cellPos, bool teleport = false);

private:

	Flipbook* _flipbookIdle[4] = {};
	Flipbook* _flipbookMove[4] = {};
	Flipbook* _flipbookAttack[4] = {};

	VectorInt _cellPos = {};
	Vector _speed = {};
	Dir _dir = DIR_DOWN;
	PlayerState _state = PlayerState::Idle;
	bool _keyPressed = false;

};

