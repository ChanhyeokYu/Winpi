#pragma once

class ISkill
{
public:
	ISkill() {}
	virtual ~ISkill() = default;
	virtual void Apply() abstract;

};

class MeleeSkill : public ISkill
{
public:
	MeleeSkill();
	MeleeSkill(int32 damage) : _damage(damage){}
	virtual void Apply() override;

private:
	int32 _damage = 0;
};

class RanageSkill : public ISkill
{
public:
	RanageSkill(int32 damage, int32 ranage) : _damage(damage), _ranage(ranage) {}

	virtual void Apply() override;

private:
	int32 _damage = 0;
	int32 _ranage = 0;
};

class TickSkill : public ISkill
{
public:
	TickSkill(int32 tickDamage, int32 tickTime) : _tickDamage(tickDamage), _tickTime(tickTime) {}

	virtual void Apply() override;

private:
	int32 _tickDamage = 0;
	int32 _tickTime= 0;
};