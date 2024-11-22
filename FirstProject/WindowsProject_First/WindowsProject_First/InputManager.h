#pragma once

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Donw = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	SpaceBar = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	Q = 'Q',
	E = 'E',

	KEY_1 = '1',
	KEY_2 = '2',
	KEY_3 = '3',

};

enum class KeyState
{
	None, //키 미입력
	Press, // 키 입력 유지
	Down, //키 입력
	Up, // 키 입력 중지

	End
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End),
};

class InputManager
{
	DECLARE_SINGLE(InputManager);
public:
	void Init(HWND hwnd);
	void Update();

	bool GetButton(KeyType key) { return GetState(key) == KeyState::Press; }

	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }

	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }
	POINT GetMousePos() { return _mousePos; }
private:
	KeyState GetState(KeyType key) { return _states[static_cast<int8>(key)]; }

private:
	HWND _hwnd = 0;
	vector<KeyState> _states;
	POINT _mousePos;
};

