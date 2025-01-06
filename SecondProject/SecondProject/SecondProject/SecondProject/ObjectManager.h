#pragma once

class Object;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	void SetObject(Object* _object) { _objects.push_back(_object); }
	Object* GetObject(int32 _idx) { return _objects[_idx]; }

	void AddObject(Object* _object);
	void RemoveObject(Object* _object);

	void AddPlayerObject(Object* playerobject);
	void RemovePlayerObject(Object* playerobject);

private:
	vector<Object*> _objects;
	vector<Object*> _playerObjects;
};

