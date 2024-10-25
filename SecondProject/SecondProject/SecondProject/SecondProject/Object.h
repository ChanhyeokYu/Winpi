#pragma once

struct Stat
{
	uint32 hp = 0;
	uint32 maxHp = 0;
	uint32 Attach = 0;
	uint32 Armor = 0;
};

enum class ObjectType
{
	None,
	Player,
	Monster,
};

class Object
{
public:

	Object(ObjectType _objectType);
	virtual ~Object();

public:
	virtual void Init() abstract;
	virtual void Update() abstract;

protected:
	ObjectType objectType = ObjectType::None;
	Stat stat = {};

};

