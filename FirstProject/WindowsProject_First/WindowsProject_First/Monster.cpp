#include "pch.h"
#include "Monster.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"

#include "Flipbook.h"
#include "CameraComponent.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "DevScene.h"
#include "Player.h"
#include "HitEffect.h"

Monster::Monster()
{
	_flipbookMove[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeUp");
	_flipbookMove[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeDown");
	_flipbookMove[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeLeft");
	_flipbookMove[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeRight");

	_Stat.Hp = 50;
	_Stat.maxHp = 50;
	_Stat.Attack = 10;
	_Stat.Defence = 0;
}

Monster::~Monster()
{
}

void Monster::BeginPlay()
{
	Super::BeginPlay();

	SetState(ObjectState::Move);
	SetState(ObjectState::Idle);
}

void Monster::Tick()
{
	Super::Tick();

}

void Monster::Render(HDC hdc)
{
	Super::Render(hdc);

}

void Monster::TickIdle()
{
	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
		return;

	// Find Player
	if (_target == nullptr)
		_target = scene->FindClosestPlayer(GetCellPos());

	if (_target)
	{
		VectorInt dir = _target->GetCellPos() - GetCellPos();
		int32 dist = abs(dir.x) + abs(dir.y);
		if (dist == 1)
		{
			SetDir(GetLookAtDir(_target->GetCellPos()));
			SetState(ObjectState::Skill);
			_waitSeconds = 0.5f; // 공격 종료 시간
		}
		else
		{
			vector<VectorInt> path;
			if (scene->FindPath(GetCellPos(), _target->GetCellPos(), OUT path))
			{
				if (path.size() > 1)
				{
					VectorInt nextPos = path[1];
					if (scene->CanGo(nextPos))
					{
						SetCellPos(nextPos);
						SetState(ObjectState::Move);
					}
				}
				else
					SetCellPos(path[0]);
			}
		}
	}
}

void Monster::TickMove()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	Vector dir = (_destPos - _pos);
	if (dir.Length() < 5.f)
	{
		SetState(ObjectState::Idle);
	}
	else
	{

		bool horizonial = abs(dir.x) > abs(dir.y);
		if (horizonial)
		{
			SetDir(dir.x < 0 ? DIR_LEFT : DIR_RIGHT);
		}
		else
		{
			SetDir(dir.y < 0 ? DIR_UP : DIR_DOWN);

		}

		switch (_dir)
		{
		case DIR_UP:
			_pos.y -= 50 * deltaTime;
			break;
		case DIR_DOWN:
			_pos.y += 50 * deltaTime;
			break;
		case DIR_LEFT:
			_pos.x -= 50 * deltaTime;
			break;
		case DIR_RIGHT:
			_pos.x += 50 * deltaTime;
			break;
		default:
			break;
		}
	}
}

void Monster::TickSkill()
{
	if (_flipbook == nullptr)
		return;

	if (_waitSeconds > 0)
	{
		float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
		_waitSeconds = max(0, _waitSeconds - deltaTime);
		return;
	}

	{
		DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
		if (scene == nullptr)
			return;

		Creature* creature = scene->GetCreatureAt(GetFrontCellPos());
		if (creature)
		{
			scene->SpawnObject<HitEffect>(GetFrontCellPos());
			creature->OnDamaged(this);
		}

		SetState(ObjectState::Idle);
	}
}

void Monster::UpdateAnumation()
{
	SetFlipbook(_flipbookMove[_dir]);
}
