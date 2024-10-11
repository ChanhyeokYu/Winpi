#pragma once
#include "Object.h"
class Player :
    public Object
{
public:
    Player();
    virtual ~Player() override;

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;

};

