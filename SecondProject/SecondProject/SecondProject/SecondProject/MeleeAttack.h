#pragma once
#include "IsAttack.h"

class Object;
// ���� �Ŵ������� �ְ� ���� ��ü �Լ�(���� ����)

class MeleeAttack :
    public IsAttack
{
public:
    MeleeAttack();
    virtual ~MeleeAttack() override;

public:
    virtual void operator()(Object& attacker, Object& target) override;

};

