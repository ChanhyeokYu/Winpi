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
	if (_target == nullptr)
	{
		_pos.x += _Stat.Speed * delteTime * cos(_angle);
		_pos.y -= _Stat.Speed * delteTime * sin(_angle);

		_sumTime += delteTime;
		if (_sumTime >= 0.2f)
		{
			const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
			for (Object* object : objects)
			{
				if (object->GetObjectType() == ObjectType::Monster)
				{
					_target = object;
					break;
				}
			}
		}
	}
	else
	{
		Vector dir = _target->GetPos() - GetPos();
		dir.Normalize();

		Vector	movedir = dir * _Stat.Speed* delteTime;
		_pos += movedir;
	}
	
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
		Vector p1 = GetPos();
		Vector p2 = object->GetPos();

		Vector dir = p2 - p1;
		float dist = dir.Length();

		// ���� ���� �Ÿ� ���
		//const float dx = p1.x - p2.x;
		//const float dy = p1.y - p2.y;
		//float dist = sqrt(dx * dx + dy * dy);

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
