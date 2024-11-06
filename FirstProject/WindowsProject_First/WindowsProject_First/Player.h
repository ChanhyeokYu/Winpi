#pragma once
#include "FlipbookActor.h"

class Flipbook;
class Collider;
class BoxCollider;

enum class PlayerState
{
	//Idle,
	MoveGround,
	JumpFall,
	//Skill,
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

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);

	void SetState(PlayerState playerState);
	PlayerState GetState() { return _state; }
	
private:
	void TickInput();
	virtual void TickMoveGround();
	virtual void TickJumpFall();

private:
	void Jump();
	void TickGravity();
	void AdjustCollisionPos(BoxCollider* b1, BoxCollider* b2);

private:
	Flipbook* _flipbookUp = nullptr;
	Flipbook* _flipbookDown = nullptr;
	Flipbook* _flipbookLeft = nullptr;
	Flipbook* _flipbookRight = nullptr;

private:
	Vector _speed = {};
	int32 _gravity = 1;

	PlayerState _state = PlayerState::JumpFall;

};

