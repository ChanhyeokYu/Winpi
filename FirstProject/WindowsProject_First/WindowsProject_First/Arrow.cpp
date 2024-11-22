#include "pch.h"
#include "Arrow.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Flipbook.h"
#include "SceneManager.h"
#include "DevScene.h"
#include "Creature.h"
#include "HitEffect.h"

Arrow::Arrow()
{
	_flipbookMove[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_ArrowUp");
	_flipbookMove[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_ArrowDown");
	_flipbookMove[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_ArrowLeft");
	_flipbookMove[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_ArrowRight");
}

Arrow::~Arrow()
{
}

void Arrow::BeginPlay()
{
	Super::BeginPlay();
	UpdateAnumation();
}

void Arrow::Tick()
{
	Super::Tick();

}

void Arrow::Render(HDC hdc)
{
	Super::Render(hdc);

}

void Arrow::TickIdle()
{
	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
		return;

	VectorInt deltaXY[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	VectorInt nextPos = _cellPos + deltaXY[_dir];

	if (CanGo(nextPos))
	{
		SetCellPos(nextPos);
		SetState(ObjectState::Move);
	}
	else
	{
		Creature* creature = scene->GetCreatureAt(nextPos);
		if (creature)
		{
			scene->SpawnObject<HitEffect>(nextPos);
			//creature->OnDamaged(this);
		}

		scene->RemoveActor(this);
	}
}

void Arrow::TickMove()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	Vector dir = (_destPos - _pos);
	if (dir.Length() < 5.f)
	{
		SetState(ObjectState::Idle);
		_pos = _destPos;
	}
	else
	{
		switch (_dir)
		{
		case DIR_UP:
			_pos.y -= 600 * deltaTime;
			break;
		case DIR_DOWN:
			_pos.y += 600 * deltaTime;
			break;
		case DIR_LEFT:
			_pos.x -= 600 * deltaTime;
			break;
		case DIR_RIGHT:
			_pos.x += 600 * deltaTime;
			break;
		}
	}
}

void Arrow::UpdateAnumation()
{
	SetFlipbook(_flipbookMove[_dir]);

}
