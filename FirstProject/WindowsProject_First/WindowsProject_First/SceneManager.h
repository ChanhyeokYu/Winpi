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

	Vector GetCameraPos() { return _cameraPos; }
	void SetCameraPos(Vector cameraPos) { _cameraPos = cameraPos; }

private:
	class Scene* _scene;
	SceneType _sceneType = SceneType::None;

	Vector _cameraPos = { 400,400 };

};

