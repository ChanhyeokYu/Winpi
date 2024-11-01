#pragma once
#include "Scene.h"

class actor;
class GameObject;
class UI;

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

    void AddActor(actor* Actor);
    void RemoveActor(actor* Actor);


public:
    vector<actor*> _actors[LAYER_MAXCOUNT];

    vector<UI*> _uis;

};

