#include "pch.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::AddObject(Object* _object)
{
	if (_object == nullptr)
	{
		return;
	}
	
	_objects.push_back(_object);

}

void ObjectManager::RemoveObject(Object* _object)
{
	if (_object == nullptr)
	{
		return;
	}

	auto findIt = find(_objects.begin(), _objects.end(), _object);
	if (findIt == _objects.end())
	{
		return;
	}

	_objects.erase(findIt);

}
