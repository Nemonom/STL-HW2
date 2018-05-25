#pragma once

#include "header.h"
#include "GameFrameWork.h"

CGameFrameWork::CGameFrameWork()
{
}

CGameFrameWork::~CGameFrameWork()
{
}

bool CGameFrameWork::Begin(HWND hWnd, HINSTANCE hInstance)
{
	m_hWnd = hWnd;
	m_hInstance = hInstance;

	return true;
}

void CGameFrameWork::Render(HDC hdc)
{
}

void CGameFrameWork::Update(const float & frame_time)
{
}

void CGameFrameWork::Key_Event(UINT iMessage, WPARAM wParam)
{
	if (iMessage == WM_KEYDOWN)
		Key_Down(wParam);
	else if (iMessage == WM_KEYUP)
		Key_Up(wParam);
}

void CGameFrameWork::Key_Down(WPARAM wParam)
{
	switch (wParam)
	{
	}
}

void CGameFrameWork::Key_Up(WPARAM wParam)
{
	switch (wParam)
	{
	case 'Q':
		DestroyWindow(m_hWnd);
		break;
	}
}

void CGameFrameWork::Mouse_Event(UINT iMessage, WPARAM wParam, LPARAM lParam)
{

}

bool CGameFrameWork::Destroy()
{

}

void CGameFrameWork::Init()
{
	
}
