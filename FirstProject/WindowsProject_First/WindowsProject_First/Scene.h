#pragma once

class actor;
class UI;

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

public:
	void AddActor(actor* Actor);
	void RemoveActor(actor* Actor);


public:
	vector<actor*> _actors[LAYER_MAXCOUNT];

	vector<UI*> _uis;
	actor* _background;

};

