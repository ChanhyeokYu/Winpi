#include "pch.h"
#include "ResourceManager.h"
#include "LineMesh.h"

ResourceManager::~ResourceManager()
{
	Clear();
}

void ResourceManager::Init()
{
	LineMesh* mesh = new LineMesh();
	mesh->Load(L"Player.txt");

	_lineMeshes[L"Player"] = mesh;
}

void ResourceManager::Clear()
{
	// 리소스 매니저과 관리하는 객체 모두 소멸(메모리 누수 방지)
	// 리소스 매니저는 프로그램이 끝나기 전까지 소멸하지 않기 때문에
	// 리소스 매니저의 소멸은 프로그램의 종료
	for (auto mesh : _lineMeshes)
		SAFE_DELETE(mesh.second);

	_lineMeshes.clear();
}

const LineMesh* ResourceManager::GetLineMesh(wstring key)
{
	auto findit = _lineMeshes.find(key);
	if (findit == _lineMeshes.end())
	{
		return nullptr;
	}

	return findit->second;
}
