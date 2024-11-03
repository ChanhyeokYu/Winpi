#pragma once
#include "Sequence.h"
class MainSequence :
    public Sequence
{
public:
	DECLARE_SINGLE(MainSequence);

public:
	virtual void Init() override;
	virtual void Update() override;

};

