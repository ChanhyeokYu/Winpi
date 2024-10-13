#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ObjectManager.h"

Missile::Missile() : Object(ObjectType::Projectile)
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
	_Stat.Hp = 1;
	_Stat.maxHp= 1;
	_Stat.Speed = 600;

}

void Missile::Update()
{
	// ������ �ð�
	float delteTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// �ð��� ���� �̵�(����ü�� �̵��ӵ�)
	_pos.y -= delteTime * _Stat.Speed;
	
	//������Ʈ �Ŵ������� �浹�� ��ǥ �˻�
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		// �ڽ��̸� �ѱ��
		if (object == this)
		{
			continue;

		}
		
		// ���Ͱ� �ƴϸ� �ѱ��
 		if (object->GetObjectType() != ObjectType::Monster)
		{
			continue;
		}

		//���� ��ġ�� ��� ��ġ Ȯ��
		Pos p1 = GetPos();
		Pos p2 = object->GetPos();

		// ���� ���� �Ÿ� ���
		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = sqrt(dx * dx + dy * dy);

		// ���� ���� �ȿ� ����� ������ ���� ��� ����
		if (dist <25)
		{
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;
		}

	}
	// ����ü�� �ʹ� �ָ� ���ư����� ����
	if (_pos.y <-200)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
