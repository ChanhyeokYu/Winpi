#pragma once
#include "UI.h"

class Sprite;

enum ButtonState
{
	BS_Default,
	//BS_Hovered,
	BS_Pressed,
	BS_Clicked,

	BS_MaxCount
};

class Button : public UI
{
	using Super = UI;
public:
	Button();
	virtual ~Button();

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	void	SetSize(VectorInt size) { _size = size; }
	Sprite* GetSprite(ButtonState state) { _Sprites[state]; }
	
	void SetCurrentSprite(Sprite* sprite) { _currentSprite = sprite; }
	void SetSprite(Sprite* sprite, ButtonState state) { _Sprites[state] = sprite; }
	void SetButtonState(ButtonState state);

	void OnClickButton() {}

protected:
	Sprite* _currentSprite = nullptr;
	Sprite* _Sprites[BS_MaxCount] = {};
	ButtonState _state = BS_Default;

	float _sumTime = 0.f;

public:

	//void(*_onClickFunc)();
	/*using OnClickButtonFuncType = void(*)();
	OnClickButtonFuncType _onClickFunc = nullptr;*/

	/*using OnClickButtonMemFuncType = void(Button::*)();
	Button* _owner = nullptr;
	OnClickButtonMemFuncType _onClickMemFunc = nullptr;*/

	template<typename T>
	void AddOnClickDelegate(T* owner, void(T::* func)())
	{
		_onClick = [owner, func]()
			{
				(owner->*func)();
			};
	}

	std::function<void(void)> _onClick = nullptr;

};

