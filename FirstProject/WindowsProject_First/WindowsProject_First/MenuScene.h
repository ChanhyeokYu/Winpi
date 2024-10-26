#pragma once
#include "Scene.h"
class MenuScene :
    public Scene
{
public:
    MenuScene();
    virtual ~MenuScene() override;

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;



};

