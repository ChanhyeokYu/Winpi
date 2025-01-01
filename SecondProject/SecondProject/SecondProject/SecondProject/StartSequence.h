#pragma once

#include "Sequence.h"

class StartSequence : Sequence
{
public:
	StartSequence() {}
	~StartSequence() {}
public:

	virtual void Init() override;
	virtual void Update() override;

public:
	void test();
};

