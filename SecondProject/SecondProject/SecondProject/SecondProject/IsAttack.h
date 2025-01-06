#pragma once

class Object;

class IsAttack
{
public:
	virtual ~IsAttack();
	virtual void operator()(Object& attackter, Object& target) abstract;
};

