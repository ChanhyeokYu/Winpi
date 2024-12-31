#include "pch.h"
#include "MainSequence.h"
#include "MemoryPool.h"
#include "BattleManager.h"

void MainSequence::Init()
{
	MemoryPool pool(sizeof(MyStruct), 10);

	MyStruct* obj1 = static_cast<MyStruct*>(pool.Allocate());

	obj1->x = 11;
	obj1->y = 3.14;

	pool.Dellocate(obj1);
}

void MainSequence::Update()
{
	while (true)
	{
		BattleManager& manager = BattleManager::GetInstance();
		manager.test();
	}
}
