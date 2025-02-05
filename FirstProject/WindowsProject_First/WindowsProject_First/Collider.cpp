#include "pch.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "Actor.h"

Collider::Collider(ColliderType colliderType) : _colliderType(colliderType)
{
}

Collider::~Collider()
{
}

void Collider::BeginPlay()
{
}

void Collider::TickComponent()
{
}

void Collider::Render(HDC hdc)
{
}

bool Collider::CheckCollision(Collider* other)
{

	uint32 layer = other->GetCollisionLayer();
	if (_collisionflag & (1<< layer))
	{
		return true;
	}

	return false;
}

bool Collider::CheckCollisionBox2Box(BoxCollider* b1, BoxCollider* b2)
{

	RECT r1 = b1->GetRect();
	RECT r2 = b2->GetRect();

	RECT intersect = {};
	return ::IntersectRect(&intersect, &r1, &r2);

}

bool Collider::CheckCollisionSphere2Box(SphereCollider* s1, BoxCollider* b2)
{


	return false;
}

bool Collider::CheckCollisionSphere2Sphere(SphereCollider* s1, SphereCollider* s2)
{

	Vector p1 = s1->GetOwner()->GetPos();
	float r1 = s1->GetRadius();

	Vector p2 = s2->GetOwner()->GetPos();
	float r2 = s2->GetRadius();

	Vector dir = p1 - p2;
	float dist = dir.Length();

	return dist <= r1 + r2;
}

void Collider::AddCollisionFlagLayer(COLLISION_LAYER_TYPE layer)
{
	_collisionflag |= (1 << layer);
}

void Collider::RemoveCollisionFlagLayer(COLLISION_LAYER_TYPE layer)
{
	_collisionflag &= ~(1 << layer);
}
