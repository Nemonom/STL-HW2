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
	UINT iMessage;
	bool fin;

public:
	Key() {};
	Key(int x, int y, float ftime, UINT iMessage) : x(x), y(y), ftime(ftime), fin(false), iMessage(iMessage) {};
	Key(const Key& other) : x(other.x), y(other.y), ftime(other.ftime), fin(false), iMessage(other.iMessage) {};
	~Key() {};

	void show() const 
	{
		std::cout << x << " " << y << " " << ftime << " " << iMessage << std::endl;
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

	void Put_Key(int x, int y, UINT iM);

private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;

	Sound_Func snd;

	CBitmapObject m_back;
	std::vector<CBitmapObject> m_obj; // 누르는거
	std::list<Key> m_key; // 저장할 데이터
	std::vector<Key> m_playkey; // 불러온 데이터

	// 시간 측정
	float m_time{ 0.0f };

	state m_gamestate = state::Normal;
};

