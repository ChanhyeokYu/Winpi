#pragma once

class Object;

class BattleManager
{
public:
	DECLARE_SINGLE(BattleManager);

public:
	void ApplyDamage(Object* subject, Object* target);

private:
	

};

