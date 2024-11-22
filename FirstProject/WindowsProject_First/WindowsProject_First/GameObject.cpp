#include "pch.h"
#include "GameObject.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"

#include "Flipbook.h"
#include "CameraComponent.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "DevScene.h"


GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{
}

void GameObject::BeginPlay()
{
	Super::BeginPlay();

	SetState(ObjectState::Move);
	SetState(ObjectState::Idle);

}

void GameObject::Tick()
{
	Super::Tick();

	switch (_state)
	{
	case ObjectState::Idle:
		TickIdle();
		break;
	case ObjectState::Move:
		TickMove();
		break;
	case ObjectState::Skill:
		TickSkill();
		break;
	default:
		break;
	}

}

void GameObject::Render(HDC hdc)
{
	Super::Render(hdc);

}


void GameObject::SetState(ObjectState ObjectState)
{
	if (_state == ObjectState)
	{
		return;
	}

	_state = ObjectState;
	UpdateAnumation();

}

void GameObject::SetDir(Dir dir)
{
	_dir = dir;
	UpdateAnumation();
}

bool GameObject::HasReachedDest()
{
	Vector dir = (_destPos - _pos);
	return (dir.Length() < 10.f);
}

bool GameObject::CanGo(VectorInt cellPos)
{
	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
	{
		return false;
	}
	return scene->CanGo(cellPos);
}

Dir GameObject::GetLookAtDir(VectorInt cellPos)
{
	VectorInt dir = cellPos - GetCellPos();
	if (dir.x > 0)
	{
		return DIR_RIGHT;
	}
	else if (dir.x < 0)
	{
		return DIR_LEFT;
	}
	else if (dir.y > 0)
	{
		return DIR_DOWN;
	}
	else 
	{
		return DIR_UP;
	}
}

void GameObject::SetCellPos(VectorInt cellPos, bool teleport)
{
	_cellPos = cellPos;

	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
	{
		return;
	}

	_destPos = scene->ConvertPos(cellPos);

	if (teleport)
	{
		_pos = _destPos;
	}
}

VectorInt GameObject::GetFrontCellPos()
{
	switch (_dir)
	{
	case DIR_UP:
		return _cellPos + VectorInt{ 0,-1 };
		break;
	case DIR_DOWN:
		return _cellPos + VectorInt{ 0,1 };
		break;
	case DIR_LEFT:
		return _cellPos + VectorInt{ -1,0 };
		break;
	case DIR_RIGHT:
		return _cellPos + VectorInt{ 1,0 };
		break;
	default:
		break;
	}

	return _cellPos;

}

