#pragma once

class actor;
class UI;
class Creature;

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
	virtual void AddActor(actor* Actor);
	virtual void RemoveActor(actor* Actor);

	Creature* GetCreatureAt(VectorInt cellPos);

public:
	vector<actor*> _actors[LAYER_MAXCOUNT];

	vector<UI*> _uis;
	actor* _background;

};

