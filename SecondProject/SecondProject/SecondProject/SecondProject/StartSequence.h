#pragma once

#include "Sequence.h"

class Player;

class StartSequence : Sequence
{
public:
	StartSequence() {}
	~StartSequence() {}
public:

	virtual void Init() override;
	virtual void Update() override;

public:
	void SelectStart(int32 selectNum);
	void NewStart();
	void ContineStart();
};

