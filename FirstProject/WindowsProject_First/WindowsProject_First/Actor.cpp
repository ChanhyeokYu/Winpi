#include "pch.h"
#include "actor.h"
#include "Component.h"
#include "Collider.h"

actor::actor()
{
}

actor::~actor()
{
}

void actor::BeginPlay()
{
	for (Component* component : _components)
	{
		component->BeginPlay();
	}
}

void actor::Tick()
{
	for (Component* component : _components)
	{
		component->TickComponent();
	}
}

void actor::Render(HDC hdc)
{
	for (Component* component : _components)
	{
		component->Render(hdc);
	}
}

void actor::AddComponent(Component* component)
{
	if (component == nullptr)
	{
		return;
	}

	component->SetOwner(this);
	_components.push_back(component);

}

void actor::RemoveComponent(Component* component)
{
	auto findIt = std::find(_components.begin(), _components.end(), component);
	if (findIt == _components.end())
	{
		return;
	}
	_components.erase(findIt);

}

void actor::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
}

void actor::OnComponentEndOverlap(Collider* collider, Collider* other)
{
}
