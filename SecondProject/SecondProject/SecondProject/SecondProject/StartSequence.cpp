#include "pch.h"
#include "StartSequence.h"
#include "ReadingManager.h"

void StartSequence::Init()
{
}

void StartSequence::Update()
{
}

void StartSequence::test()
{
	GET_SINGLE(ReadingManager)->OpenFile();
}
