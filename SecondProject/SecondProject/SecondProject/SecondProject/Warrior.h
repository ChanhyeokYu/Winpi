#pragma once
#include "Player.h"
class Warrior :
    public Player
{
    using Super = Player;
public:
    Warrior();
    virtual ~Warrior() override;

public:
    virtual void Init() override;
    virtual void Update() override;

    PlayerClass GetPlayerClass() { return _playerclass; }

private:
    PlayerClass _playerclass = PlayerClass::Warrior;

};

