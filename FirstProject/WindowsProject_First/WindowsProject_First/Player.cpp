#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Missile.h"
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

	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= delteTime * _Stat.Speed;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += delteTime * _Stat.Speed;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_pos.y -= delteTime * _Stat.Speed;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_pos.y += delteTime * _Stat.Speed;
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		Missile* misslie = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		misslie->SetPos(_pos);
 		GET_SINGLE(ObjectManager)->Add(misslie);
	}

}

void Player::Render(HDC hdc)
{
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player");
	if (mesh)
	{
		mesh->Render(hdc, _pos);
	}
}
