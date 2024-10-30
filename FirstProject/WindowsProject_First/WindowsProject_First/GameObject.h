#pragma once

class Component;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

public:
	virtual void Start();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetPos(Vector pos) { pos = _pos; }
	Vector GetPos() { return _pos; }

	void AddComponent(Component* component);

protected:
	Vector _pos = { 0,0 };
	vector<Component*> _components;
};

