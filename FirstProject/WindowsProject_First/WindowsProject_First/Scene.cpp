#include "pch.h"
#include "Scene.h"
#include "Actor.h"
#include "UI.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "Creature.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
	for (const vector<actor*>& Actors : _actors)
	{
		for (actor* Actor : Actors)
		{
			Actor->BeginPlay();
		}
	}

	for (UI* ui : _uis)
	{
		ui->BeginPlay();
	}
}

void Scene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	GET_SINGLE(CollisionManager)->Update();

	for (const vector<actor*>& Actors : _actors)
	{
		for (actor* Actor : Actors)
		{
			Actor->Tick();
		}
	}

	for (UI* ui : _uis)
	{
		ui->Tick();
	}
}

void Scene::Render(HDC hdc)
{
	vector<actor*>& actors = _actors[LAYER_OBJECT];
	::sort(actors.begin(), actors.end(), [=](actor* a, actor* b)
		{
			return a->GetPos().y < b->GetPos().y;
		});

	for (const vector<actor*>& Actors : _actors)
	{
		for (actor* Actor : Actors)
		{
			Actor->Render(hdc);
		}
	}

	for (UI* ui : _uis)
	{
		ui->Render(hdc);
	}
}

void Scene::AddActor(actor* Actor)
{
	if (Actor == nullptr)
	{
		return;
	}

	_actors[Actor->GetLayer()].push_back(Actor);

}

void Scene::RemoveActor(actor* Actor)
{
	if (Actor == nullptr)
	{
		return;
	}

	vector<actor*>& v = _actors[Actor->GetLayer()];

	v.erase(std::remove(v.begin(), v.end(), Actor), v.end());


}

Creature* Scene::GetCreatureAt(VectorInt cellPos)
{
	for (actor* Actor : _actors[LAYER_OBJECT])
	{
		Creature* creature = dynamic_cast<Creature*>(Actor);
		if (creature && creature->GetCellPos() == cellPos)
		{
			return creature;
		}
	}

	return nullptr;
}
