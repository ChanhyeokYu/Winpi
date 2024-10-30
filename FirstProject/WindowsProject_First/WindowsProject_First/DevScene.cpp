#include "pch.h"
#include "DevScene.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Utils.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sprite.h"
#include "actor.h"
#include "Spriteactor.h"
#include "Player.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "PlayerMoveScript.h"
#include "Flipbook.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	GET_SINGLE(ResourceManager)->LoadTexture(L"Stage01", L"Sprite\\Map\\Stage01.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Potion", L"Sprite\\UI\\Mp.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerDown", L"Sprite\\Player\\PlayerDown.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerUp", L"Sprite\\Player\\PlayerUp.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerLeft", L"Sprite\\Player\\PlayerLeft.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerRight", L"Sprite\\Player\\PlayerRight.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"Start", L"Sprite\\UI\\Start.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Edit", L"Sprite\\UI\\Edit.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Exit", L"Sprite\\UI\\Exit.bmp");

	GET_SINGLE(ResourceManager)->CreateSprite(L"Stage01", GET_SINGLE(ResourceManager)->GetTexture(L"Stage01"));
	GET_SINGLE(ResourceManager)->CreateSprite(L"Start_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Start"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Start_On", GET_SINGLE(ResourceManager)->GetTexture(L"Start"), 150, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Edit_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Edit"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Edit_On", GET_SINGLE(ResourceManager)->GetTexture(L"Edit"), 150, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Exit_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Exit"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Exit_On", GET_SINGLE(ResourceManager)->GetTexture(L"Exit"), 150, 0, 150, 150);
	
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerUp");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveUp");
		fb->SetInfo({ texture, L"FB_MoveUp", {200,200},0,9,1,0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerDown");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveDown");
		fb->SetInfo({ texture, L"FB_MoveDown", {200,200},0,9,1,0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerLeft");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveLeft");
		fb->SetInfo({ texture, L"FB_MoveLeft", {200,200},0,9,1,0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerRight");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveRight");
		fb->SetInfo({ texture, L"FB_MoveRight", {200,200},0,9,1,0.5f });
	}

	{
		Sprite* sprtie = GET_SINGLE(ResourceManager)->GetSprite(L"Stage01");

		Spriteactor* background = new Spriteactor();
		background->SetSprite(sprtie);

		const VectorInt size = sprtie->GetSize();
		background->SetPos(Vector(size.x / 2, size.y / 2));
		//background->SetPos(Vector{ 0,0, });
		_actors.push_back(background);
	}

	{
		Sprite* sprtie = GET_SINGLE(ResourceManager)->GetSprite(L"Start_On");

		Player* player = new Player();
		_actors.push_back(player);

	}


	for (actor* Actor : _actors)
	{
		Actor->BeginPlay();
	}

}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	for (actor* Actor : _actors)
	{
		Actor->Tick();
	}


}

void DevScene::Render(HDC hdc)
{
	//Texture* tex = GET_SINGLE(ResourceManager)->GetTexture(L"Stage01");
	//Sprite* sprite = GET_SINGLE(ResourceManager)->GetSprite(L"Start_On");

	//::BitBlt(hdc, 
	//	0, 
	//	0, 
	//	GWinSizeX, 
	//	GWinSizeY, 
	//	sprite->GetDC(), 
	//	sprite->GetPos().x, 
	//	sprite->GetPos().y, 
	//	SRCCOPY);

	for (actor* Actor : _actors)
	{
		Actor->Render(hdc);
	}

}
