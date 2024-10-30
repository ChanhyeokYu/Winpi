#pragma once
#include "Scene.h"

class actor;
class GameObject;

class DevScene :
    public Scene
{
public:
    DevScene();
    virtual ~DevScene() override;

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;

public:
    vector<actor*> _actors;

};

