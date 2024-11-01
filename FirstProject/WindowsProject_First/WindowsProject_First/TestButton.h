#pragma once
#include "Button.h"


class TestButton :
    public Button
{
	using Super = Button;
public:

	TestButton();
	virtual ~TestButton();

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:


};

