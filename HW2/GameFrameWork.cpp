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

	m_obj[0].OnCreatCimg(L"button/1.png");
	m_obj[1].OnCreatCimg(L"button/7.png");
	m_obj[2].OnCreatCimg(L"button/3.png");
	m_obj[3].OnCreatCimg(L"button/4.png");
	m_obj[4].OnCreatCimg(L"button/5.png");
	m_obj[5].OnCreatCimg(L"button/6.png");

	int i = 0;
	for (auto& p : m_obj)
	{
		p.SetObjRECT(RECT{ -20 * 2,-20 * 2,20 * 2,20 * 2 });
		p.SetPos(Point{ 175 + i * 90,  HEIGHT/2 + 150});
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
	switch (m_gamestate)
	{
	case state::Normal:

		break;

	case state::PlayRecord:
		if (m_playkey.empty()) break;
		
		m_time += frame_time;

		for (auto& p : m_playkey)
		{
			if (!p.fin && p.ftime <= m_time)
			{
			// 연주해랑				
			Put_Key(p.x, p.y, p.iMessage);
			p.fin = true;
			break;
			}
			else
				continue;
		}		

		if (m_time > frame_time * 60 * MAX_TIME)
		{
			Init();			
		}
		break;

	case state::StartRecord:
		m_time += frame_time;

		if (m_time > frame_time * 60 * MAX_TIME)
		{
			// 파일에 저장하기
			std::ofstream out("replay.txt", std::ios::binary);

			for (auto& p : m_key)
			{
				out << p.x 
					<< " " << p.y
					<< " " << p.ftime
					<< " " << p.iMessage
					<< " " << std::endl;
			}

			Init();
		}
		break;
	}


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
	case WM_LBUTTONUP:
		if (m_gamestate == state::PlayRecord) break;
		Put_Key(LOWORD(lParam), HIWORD(lParam), iMessage);		
	break;

	default:
		break;
	}
}

void CGameFrameWork::Menu_Input(WPARAM wparam)
{	
	switch (LOWORD(wparam))
	{
	case ID_40001: // 불러오기
	{
	if (m_gamestate == state::PlayRecord) break;

	m_playkey.clear();

	std::ifstream in("replay.txt", std::ios::binary);

	int input_x, input_y{ 0 };
	float input_ftime{ 0.0f };
	UINT input_iM;

	while (in >> input_x >> input_y >> input_ftime >> input_iM)
	{
		m_playkey.emplace_back(Key(input_x, input_y, input_ftime, input_iM));
	}

	for (const auto& p : m_playkey)
		p.show();

	break;
	}

	case ID_40003: // 불러온거 시작하기
		if (m_gamestate == state::PlayRecord) break;
		Init();
		m_gamestate = state::PlayRecord;
		break; 
	case ID_40004: // 새로 리플레이 만들기
		if (m_gamestate == state::PlayRecord) break;
		Init();
		m_gamestate = state::StartRecord;
		break;
	}
}

bool CGameFrameWork::Destroy()
{
	return false;
}

void CGameFrameWork::Init()
{
	m_key.clear();

	for (auto& p : m_playkey)
		p.fin = false;

	for (auto& p : m_obj)
	{
		if (p.GetClick())
			p.SetClick();
	}

	for (int i = 0; i < NUM; ++i)
		snd.Stop_bgm(i);

	m_gamestate = state::Normal;
	m_time = 0.0f;
}

void CGameFrameWork::Put_Key(int x, int y, UINT iM)
{
	POINT ptmouse{ x, y };
	for (int i = 0; i < NUM; ++i)
	{
		m_obj[i].SetMouseMove(POINT{ ptmouse.x, ptmouse.y });
		if (PtInRect(&m_obj[i].GetObjRECT(), ptmouse))
		{
			// 녹음중이라면
			if (m_gamestate == state::StartRecord)
			{
				Key dump(ptmouse.x, ptmouse.y, m_time, iM);
				m_key.emplace_back(dump);
			}

			if (iM == WM_LBUTTONUP)
			{
				if (m_obj[i].GetClick()) // 켜져있을때
				{
					snd.Stop_bgm(i);
					m_obj[i].SetClick();
				}
				else // 꺼져있을때
				{
					snd.Play_bgm(i);
					m_obj[i].SetClick();
				}
			}	
		}
	}
}
