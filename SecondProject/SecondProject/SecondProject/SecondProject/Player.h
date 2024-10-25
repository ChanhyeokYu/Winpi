#pragma once
#include "Object.h"

enum class PlayerClass
{
    None,
    Warrior,

};

class Player :
    public Object
{
public:
    Player();
    virtual ~Player() override;

public:
    virtual void Init() override;
    virtual void Update() override;

protected:
};

