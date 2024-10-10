#pragma once
#include "Scene.h"
class DevScene :
    public Scene
{
public:
    DevScene();
    virtual ~DevScene();

public:
    virtual void Init();
    virtual void Update();
    virtual void Render(HDC hdc);

public:
    Pos _playerPos = { 300,300 };
    float _speed = 1000;

};

