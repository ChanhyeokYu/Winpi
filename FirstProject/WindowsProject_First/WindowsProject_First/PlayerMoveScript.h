#pragma once
#include "Component.h"

class PlayerMoveScript : public Component
{
public:
	virtual void BeginPlay() override;
	virtual void TickComponent() override;
	virtual void Render(HDC hdc) override;
};

