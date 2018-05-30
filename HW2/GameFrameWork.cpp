#pragma once

#include "header.h"
#include "GameFrameWork.h"
#include "resource1.h"


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

	m_back.OnCreatCimg(L"button/testback2.jpg");

	for (int i = 0; i < NUM; ++i)
	{
		CBitmapObject dummy;
		m_obj.push_back(dummy);
	}

	m_obj[0].OnCreatCimg(L"button/green arrow back.png");
	m_obj[1].OnCreatCimg(L"button/green arrow left.png");
	m_obj[2].OnCreatCimg(L"button/green arrow right.png");
	m_obj[3].OnCreatCimg(L"button/green arrow re.png");
	m_obj[4].OnCreatCimg(L"button/option.png");
	m_obj[5].OnCreatCimg(L"button/laser unit button.png");

	int i = 0;
	for (auto& p : m_obj)
	{
		p.SetObjRECT(RECT{ -15 * 2,-15 * 2,15 * 2,15 * 2 });
		p.SetPos(Point{ 175 + i * 90,  HEIGHT/2 + 200});
		i++;
	}
	
	snd.Add_sound();

	return true;
}

void CGameFrameWork::Render(HDC hdc)
{
	m_back.draw(hdc);
	for (auto& q : m_obj)
	{
		if (!q.GetClick())
			q.drawalpha(hdc, 50);
		else
			q.draw(hdc);
	}
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
	//switch (wParam)
	//{
	//
	//}
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
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
	{
		for (auto& p : m_obj)
		{
			p.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}
	}	break;


	case WM_LBUTTONUP:
	{
		POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
		for (int i = 0; i < NUM; ++i)
		{
			if (PtInRect(&m_obj[i].GetObjRECT(), ptmouse))
			{
				if (m_obj[i].GetClick()) // ����������
				{
					snd.Stop_bgm(i);
					m_obj[i].SetClick();
				}
				else // ����������
				{
					snd.Play_bgm(i);
					m_obj[i].SetClick();
				}
			}
		}
		
	}
	break;

	default:
		break;
	}
}

void CGameFrameWork::Menu_Input(WPARAM wparam)
{	
	switch (LOWORD(wparam))
	{
	case ID_40001: // �ҷ�����

		break;
	case ID_40003: // �ҷ��°� �����ϱ�

		break; 
	case ID_40004: // ���� ���÷���

		break;
	}
}

bool CGameFrameWork::Destroy()
{
	return false;
}

void CGameFrameWork::Init()
{
	
}
