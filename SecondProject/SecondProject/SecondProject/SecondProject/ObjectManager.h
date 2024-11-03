#pragma once

class Object;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void SetObject(Object* _object) { _objects.push_back(_object); }
	Object* GetObject(int32 _idx) { return _objects[_idx]; }

	void AddObject(Object* _object);
	void RemoveObject(Object* _object);

private:
	vector<Object*> _objects;

};

