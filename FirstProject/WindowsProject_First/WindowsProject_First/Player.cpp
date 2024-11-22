#include "pch.h"
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
#include "HitEffect.h"
#include "Arrow.h"


Player::Player()
{
	_flipbookIdle[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_IdleUp");
	_flipbookIdle[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_IdleDown");
	_flipbookIdle[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_IdleLeft");
	_flipbookIdle[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_IdleRight");

	_flipbookMove[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveUp");
	_flipbookMove[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveDown");
	_flipbookMove[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveLeft");
	_flipbookMove[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveRight");

	_flipbookAttack[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_AttackUp");
	_flipbookAttack[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_AttackDown");
	_flipbookAttack[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_AttackLeft");
	_flipbookAttack[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_AttackRight");

	_flipbookBow[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_BowUp");
	_flipbookBow[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_BowDown");
	_flipbookBow[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_BowLeft");
	_flipbookBow[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_BowRight");

	_flipbookStaff[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_StaffUp");
	_flipbookStaff[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_StaffDown");
	_flipbookStaff[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_StaffLeft");
	_flipbookStaff[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_StaffRight");

	CameraComponent* camera = new CameraComponent();
	AddComponent(camera);

	_Stat.Hp = 100;
	_Stat.maxHp = 100;
	_Stat.Attack = 30;
	_Stat.Defence = 5;
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	Super::BeginPlay();

	SetState(ObjectState::Move);
	SetState(ObjectState::Idle);

}

void Player::Tick()
{
	Super::Tick();

}

void Player::Render(HDC hdc)
{
	Super::Render(hdc);

}

void Player::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	return;

	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);
	if (b1 == nullptr || b2 == nullptr)
	{
		return;
	}


	if (b2->GetCollisionLayer() == CLT_GROUND)
	{
		SetState(ObjectState::Move);
	}

}

void Player::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	return;

	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);
	if (b1 == nullptr || b2 == nullptr)
	{
		return;
	}

	if (b2->GetCollisionLayer() == CLT_GROUND)
	{
		_state = ObjectState::Move;
	}

}

void Player::TickIdle()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_keyPressed = true;
	VectorInt deltaXY[4] = { {0,-1}, {0,1}, {-1,0}, {1,0} };

	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		SetDir(DIR_UP);

		VectorInt nextPos = _cellPos + deltaXY[_dir];
		if (CanGo(nextPos))
		{
			SetCellPos(nextPos);
			SetState(ObjectState::Move);
		}
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		SetDir(DIR_DOWN);

		VectorInt nextPos = _cellPos + deltaXY[_dir];
		if (CanGo(nextPos))
		{
			SetCellPos(nextPos);
			SetState(ObjectState::Move);
		}
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		SetDir(DIR_LEFT);

		VectorInt nextPos = _cellPos + deltaXY[_dir];
		if (CanGo(nextPos))
		{
			SetCellPos(nextPos);
			SetState(ObjectState::Move);
		}
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		SetDir(DIR_RIGHT);

		VectorInt nextPos = _cellPos + deltaXY[_dir];
		if (CanGo(nextPos))
		{
			SetCellPos(nextPos);
			SetState(ObjectState::Move);
		}
	}
	else
	{
		_keyPressed = false;
		if (_state == ObjectState::Idle)
		{
			UpdateAnumation();
		}
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::KEY_1))
	{
		SetWeaponType(WeaponType::Sword);
	}
	else if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::KEY_2))
	{
		SetWeaponType(WeaponType::Bow);
	}
	else if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::KEY_3))
	{
		SetWeaponType(WeaponType::Staff);
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::SpaceBar))
	{
		SetState(ObjectState::Skill);
	}
}

void Player::TickMove()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	Vector dir = (_destPos - _pos);
	if (dir.Length() < 5.f)
	{
		SetState(ObjectState::Idle);
	}
	else
	{
		switch (_dir)
		{
		case DIR_UP:
			_pos.y -= 200 * deltaTime;
			break;
		case DIR_DOWN:
			_pos.y += 200 * deltaTime;
			break;
		case DIR_LEFT:
			_pos.x -= 200 * deltaTime;
			break;
		case DIR_RIGHT:
			_pos.x += 200 * deltaTime;
			break;
		default:
			break;
		}
	}


}

void Player::TickSkill()
{
	if (_flipbook == nullptr)
	{
		return;
	}

	if (IsAnimationEnded())
	{
		DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
		if (scene == nullptr)
		{
			return;
		}

		if (_weaponType == WeaponType::Sword)
		{
			Creature* creature = scene->GetCreatureAt(GetFrontCellPos());
			if (creature)
			{
				scene->SpawnObject<HitEffect>(GetFrontCellPos());
				creature->OnDamaged(this);

			}
		}
		else if (_weaponType == WeaponType::Bow)
		{
			Arrow* arrow = scene->SpawnObject<Arrow>(_cellPos);
			arrow->SetDir(_dir);
		}
		SetState(ObjectState::Idle);
	}

}

void Player::UpdateAnumation()
{
	switch (_state)
	{
	case ObjectState::Idle:
		if (_keyPressed)
		{
			SetFlipbook(_flipbookMove[_dir]);
		}
		else
		{
			SetFlipbook(_flipbookIdle[_dir]);
		}
		break;
	case ObjectState::Move:
		SetFlipbook(_flipbookMove[_dir]);
		break;
	case ObjectState::Skill:
		if (_weaponType == WeaponType::Sword)
		{
			SetFlipbook(_flipbookAttack[_dir]);
		}
		else if (_weaponType == WeaponType::Bow)
		{
			SetFlipbook(_flipbookBow[_dir]);
		}
		else if (_weaponType == WeaponType::Staff)
		{
			SetFlipbook(_flipbookStaff[_dir]);
		}
		break;
	default:
		break;
	}
}

