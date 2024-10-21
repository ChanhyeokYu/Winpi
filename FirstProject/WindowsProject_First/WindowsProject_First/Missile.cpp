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
	// 프레임 시간
	float delteTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	// 시간에 따른 이동(투사체의 이동속도)
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
	
	//오브젝트 매니저에서 충돌할 목표 검색
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		// 자신이면 넘기기
		if (object == this)
		{
			continue;

		}
		
		// 몬스터가 아니면 넘기기
 		if (object->GetObjectType() != ObjectType::Monster)
		{
			continue;
		}

		//나의 위치와 대상 위치 확인
		Vector p1 = GetPos();
		Vector p2 = object->GetPos();

		Vector dir = p2 - p1;
		float dist = dir.Length();

		// 대상과 나의 거리 계산
		//const float dx = p1.x - p2.x;
		//const float dy = p1.y - p2.y;
		//float dist = sqrt(dx * dx + dy * dy);

		// 일정 범위 안에 대상이 있을시 나와 대상 삭제
		if (dist <25)
		{
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;
		}

	}
	// 투사체가 너무 멀리 날아갔을시 삭제
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
