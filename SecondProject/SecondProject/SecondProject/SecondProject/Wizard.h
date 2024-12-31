#pragma once
#include "Player.h"
class Wizard :
    public Player
{
    using Super = Player;
public:
    Wizard();
    virtual ~Wizard() override;

public:
    virtual void Init() override;
    virtual void Update() override;

    PlayerClass GetPlayerclass() { return _playerclass; }

private:
    PlayerClass _playerclass = PlayerClass::Wizard;

};

