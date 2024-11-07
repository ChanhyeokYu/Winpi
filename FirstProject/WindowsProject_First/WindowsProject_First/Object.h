#pragma once

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile,
};

class Object
{
public:
	Object(ObjectType objecType);
	virtual ~Object();

public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _objectType; }


	Pos GetPos() { return _pos; }
	void SetPos(Pos pos) { _pos = pos; }

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }

protected:
	ObjectType _objectType = ObjectType::None;
	Stat _Stat = {};
	Pos _pos = {};
	Dir _dir = Dir::DIR_LEFT;
	float _radius = 50.f;

};

