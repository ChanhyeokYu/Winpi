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

};

