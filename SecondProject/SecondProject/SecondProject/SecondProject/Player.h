#pragma once
#include "Object.h"

enum class PlayerClass
{
    None,
    Warrior,
    Wizard,

};

class Player :
    public Object
{
public:
    Player(PlayerClass _playerclass);
    virtual ~Player() override;

public:
    virtual void Init() override;
    virtual void Update() override;

protected:
};

