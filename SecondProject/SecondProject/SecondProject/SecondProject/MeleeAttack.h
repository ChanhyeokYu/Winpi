#pragma once
#include "IsAttack.h"

class Object;
// 전투 매니저에서 주고 받을 객체 함수(전투 정보)

class MeleeAttack :
    public IsAttack
{
public:
    MeleeAttack();
    virtual ~MeleeAttack() override;

public:
    virtual void operator()(Object& attacker, Object& target) override;

};

