#pragma once

class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void Clear();

public:
	void ChangeSdcene(SceneType sceneType);

	Scene* GetCurrentScene(){ return _scene; }

private:
	class Scene* _scene;
	SceneType _sceneType = SceneType::None;

};

