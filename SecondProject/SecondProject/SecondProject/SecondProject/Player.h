#pragma once
#include "Object.h"
#include "ISkill.h"

enum class PlayerClass
{
    None,
    Warrior,
    Wizard,
};

enum class SkillType
{
    None,
    MeleeType,
    RangeType,
    TickType,
};

class Player :
    public Object
{
    using Super = Object;

public:
    Player(PlayerClass _playerclass);

    virtual ~Player() override;

public:
    virtual void Init() override;
    virtual void Update() override;
    void Settingskill(unique_ptr<ISkill> skill);

protected:

private:
    unique_ptr<ISkill> _skill;

};

