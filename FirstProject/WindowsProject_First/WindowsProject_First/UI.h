#pragma once

class UI
{
public:
	UI();
	virtual ~UI();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render(HDC hdc);

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }

	RECT GetRect();
	bool IsMouseInRect();

protected:
	Vector _pos = { 400, 300 };
	VectorInt _size = { 150, 150 };
	
};

