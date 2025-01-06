#include "pch.h"
#include "ObjectManager.h"


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

void ObjectManager::AddPlayerObject(Object* playerobject)
{
	if (playerobject == nullptr)
	{
		return;
	}

	_playerObjects.push_back(playerobject);

}

void ObjectManager::RemovePlayerObject(Object* playerobject)
{
	if (playerobject == nullptr)
	{
		return;
	}

	auto findIt = find(_playerObjects.begin(), _playerObjects.end(), playerobject);
	if (findIt == _playerObjects.end())
	{
		return;
	}

	_playerObjects.erase(findIt);

}
