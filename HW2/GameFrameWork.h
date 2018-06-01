#pragma once
#include <Windows.h>
#include <vector>
#include <list>
#include "BitmapObject.h"
#include "Sound.h"

class Key
{
public:
	int x;
	int y;
	float ftime;
	bool fin;

public:
	Key() {};
	Key(int x, int y, float ftime) : x(x), y(y), ftime(ftime), fin(false) {};
	Key(const Key& other) : x(other.x), y(other.y), ftime(other.ftime), fin(false) {};
	~Key() {};

	void show() const 
	{
		std::cout << x << " " << y << " " << ftime << std::endl;
	}
};

class CGameFrameWork
{
public:
	CGameFrameWork();
	~CGameFrameWork();

public:
	bool Begin(HWND hWnd, HINSTANCE hInstance);

	void Render(HDC hdc);
	void Update(const float &frame_time = 0.017f);

	void Key_Event(UINT iMessage, WPARAM wParam);
	void Key_Down(WPARAM wParam);
	void Key_Up(WPARAM wParam);

	void Mouse_Event(UINT iMessage, WPARAM wParam, LPARAM lParam);

	void Menu_Input(WPARAM wparam);

	bool Destroy();
	
	void Init();

private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;

	Sound_Func snd;

	CBitmapObject m_back;
	std::vector<CBitmapObject> m_obj; // 누르는거
	std::list<Key> m_key; // 연주할 데이터

	// 시간 측정
	float m_time{ 0.0f };

	state m_gamestate = state::Normal;
};

