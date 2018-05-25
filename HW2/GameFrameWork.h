#pragma once
#include <Windows.h>

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

	bool Destroy();
	
	void Init();

private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;
		
};

