#include "pch.h"
#include "SceneManager.h"
#include "DevScene.h"
#include "EditScene.h"
#include "MenuScene.h"
#include "FortressScene.h"

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	// 상속으로 받아온 씬 타입에 따른 업데이트
	if (_scene)
	{
		_scene->Update();
	}
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}

void SceneManager::Clear()
{
	SAFE_DELETE(_scene);
}

void SceneManager::ChangeSdcene(SceneType sceneType)
{
	// 씬 교체

	// 교체 시 씬이 같은 경우 리턴
	if (_sceneType == sceneType)
	{
		return;
	}
	// 교체할 씬 준비
	Scene* newScene = nullptr;

	// 타입에 맞는 씬 교체
	switch (sceneType)
	{
	case SceneType::None:
		break;

	case SceneType::DevScene:
		newScene = new DevScene();
		break;

	case SceneType::EditScene:
		newScene = new EditScene();
		break;

	case SceneType::MenuScene:
		newScene = new MenuScene();
		break;

	case SceneType::FortressScene:
		newScene = new FortressScene();
		break;

	default:
		break;
	}

	// 기존 씬 삭제
	SAFE_DELETE(_scene);

	// 기존 씬에 새로운 씬 대입
	_scene = newScene;
	_sceneType = sceneType;

	// 새로운 씬 초기화
	newScene->Init();

}
