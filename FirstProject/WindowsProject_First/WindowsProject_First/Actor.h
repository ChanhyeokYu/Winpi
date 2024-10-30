#pragma once
class actor
{
public:
	actor();
	virtual ~actor();

public:
	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render(HDC hdc);

	void SetPos(Vector pos) { pos = _pos; }
	Vector GetPos() { return _pos; }

protected:
	Vector _pos = { 0,0 };

};

