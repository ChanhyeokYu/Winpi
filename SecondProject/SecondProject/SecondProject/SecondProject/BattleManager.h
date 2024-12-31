#pragma once

class Object;

class BattleManager
{
public:
	static BattleManager& GetInstance()
	{
		static BattleManager instance;
		return instance;
	}

public:
	void ApplyDamage(Object& subject, Object& target);
	void test();

private:
	BattleManager() = default;
	BattleManager(const BattleManager& ref) = delete;
	BattleManager(BattleManager&& ref) = delete;

};

