#pragma once
#include "Scene.h"

class EditScene : public Scene
{
public:
	EditScene();
	virtual ~EditScene();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

private:
	vector<pair<POINT, POINT>> _lines;

	bool _setOrigin = true;
	POINT _lastPos = {};

};

