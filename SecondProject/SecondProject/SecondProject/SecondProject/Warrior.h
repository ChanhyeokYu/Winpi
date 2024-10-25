#pragma once
#include "Player.h"
class Warrior :
    public Player
{
public:
    Warrior();
    virtual ~Warrior() override;

public:
    virtual void Init() override;
    virtual void Update() override;

};

