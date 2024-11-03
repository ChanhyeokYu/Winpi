#pragma once

class Sequence
{
public:
	Sequence();
	virtual ~Sequence();

public:
	virtual void Init() abstract;
	virtual void Update() abstract;

};

