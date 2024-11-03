#pragma once
#include "Sequence.h"
class BattleSequence :
    public Sequence
{
public:
    DECLARE_SINGLE(BattleSequence);
    
public:
    virtual void Init() override;
    virtual void Update() override;

private:

    int32 BattleTurn = 0;
    bool MyTurn = true;


};

