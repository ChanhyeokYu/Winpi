#include "pch.h"
#include "StartSequence.h"
#include "ReadingManager.h"
#include "ObjectManager.h"

#include "Warrior.h"
#include "Wizard.h"
#include "Player.h"

void StartSequence::Init()
{
}

void StartSequence::Update()
{
}

void StartSequence::SelectStart(int32 selectNum)
{
	switch (selectNum)
	{
	case 1:
	{
		NewStart();
		break;
	}

	case 2:
	{
		ContineStart();
		break;
	}

	default:
		break;
	}
}

void StartSequence::NewStart()
{
	// 캐릭터 종류를 보여주고
	// 원하는 캐릭터 생성

	int32 n;
	cin >> n;

	Player* player = new Player(PlayerClass::None);

	switch (n)
	{
	case 1:
	{
		player = new Warrior();
		break;
	}

	case 2:
	{
		player = new Wizard();
		break;
	}

	default:
		break;
	}

	GET_SINGLE(ObjectManager)->AddPlayerObject(player);

}

void StartSequence::ContineStart()
{

}

