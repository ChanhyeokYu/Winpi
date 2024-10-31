#pragma once

class actor;

class Component
{
public:
	Component();
	virtual ~Component();

	virtual void BeginPlay() abstract;
	virtual void TickComponent() abstract;
	virtual void Render(HDC hdc) abstract;

	actor* GetOwner() { return _owner; }
	void SetOwner(actor* owner) { _owner = owner; }

protected:
	actor* _owner = nullptr;
	
};

