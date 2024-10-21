#pragma once
#include "Object.h"
class Missile :
    public Object
{
public:
    Missile();
    virtual ~Missile();

public:
    virtual void Init();
    virtual void Update();
    virtual void Render(HDC hdc);

    void SetAngle(float angle) { _angle = angle; }

protected:
    float _angle = 0.f;

    float _sumTime = 0.f;
    Object* _target = nullptr;
};

