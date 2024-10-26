#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"

Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	_Stat.Hp = 100;
	_Stat.maxHp = 100;
	_Stat.Speed = 500;

	_pos.x = 400;
	_pos.y = 400;
}

void Player::Update()
{
	float delteTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	if (_playerTurn == false)
	{
		return;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= delteTime * _Stat.Speed;
		_dir = Dir::Left;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += delteTime * _Stat.Speed;
		_dir = Dir::Right;

	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		//_pos.y -= delteTime * _Stat.Speed;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		//_pos.y += delteTime * _Stat.Speed;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Q))
	{
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::E))
	{
	}


	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{

	}

}

void Player::Render(HDC hdc)
{
	if (_dir == Dir::Left)
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshkey());
		if (mesh)
		{
			mesh->Render(hdc, _pos, 0.5f, 0.5f);
		}
	}
	else
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshkey());
		if (mesh)
		{
			mesh->Render(hdc, _pos, -0.5f, 0.5f);
		}
	}
	


	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldpen = static_cast<HPEN>(SelectObject(hdc, static_cast<HGDIOBJ>(pen)));
	//Utils::DrawLine(hdc, _pos, firePos);
	::SelectObject(hdc, oldpen);
	::DeleteObject(pen);

}

wstring Player::GetMeshkey()
{
	if (_playerType == PlayerType::MissileTank)
	{
		return L"MissileTank";
	}

	return L"CanonTank";
}

