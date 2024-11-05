#pragma once
#include "Scene.h"

class actor;
class GameObject;
class UI;
class TilemapActor;

class DevScene :
    public Scene
{

    using Super = Scene;

public:
    DevScene();
    virtual ~DevScene() override;

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;

    class TilemapActor* _tilemapActor = nullptr;

};

