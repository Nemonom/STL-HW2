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
	switch (m_gamestate)
	{
	case state::Normal:

		break;

	case state::PlayRecord:
		if (m_key.empty()) break;
		
		m_time += frame_time;

		for (auto& p : m_key)
		{
			if (!p.fin && p.ftime <= m_time)
			{
			// 연주해랑
				
			POINT ptmouse{ p.x, p.y };
			for (int i = 0; i < NUM; ++i)
			{
				if (PtInRect(&m_obj[i].GetObjRECT(), ptmouse))
				{
					// 녹음중이라면
					if (m_gamestate == state::StartRecord)
					{
						Key dump(ptmouse.x, ptmouse.y, m_time);
						m_key.emplace_back(dump);
					}

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
			p.fin = true;
			break;
			}
			else
				continue;
		}		

		if (m_time > frame_time * 60 * 5)
		{
			m_gamestate = state::Normal;
			m_time = 0.0f;
		}
		break;

	case state::StartRecord:
		m_time += frame_time;

		if (m_time > frame_time * 60 * 5)
		{
			// 파일에 저장하기
			std::ofstream out("replay.txt", std::ios::binary);

			for (auto& p : m_key)
			{
				out << p.x 
					<< " " << p.y
					<< " " << p.ftime
					<< " " << std::endl;
			}

			m_gamestate = state::Normal;
			m_time = 0.0f;
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
	{
		for (auto& p : m_obj)
		{
			p.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}
	}	break;


	case WM_LBUTTONUP:
	{
		// 연주중이면 못하게 막기
		if (m_gamestate == state::PlayRecord) break;
	
		POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
		for (int i = 0; i < NUM; ++i)
		{
			if (PtInRect(&m_obj[i].GetObjRECT(), ptmouse))
			{
				// 녹음중이라면
				if (m_gamestate == state::StartRecord)
				{
					Key dump(ptmouse.x, ptmouse.y, m_time);
					m_key.emplace_back(dump);
				}

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

	m_key.clear();

	std::ifstream in("replay.txt", std::ios::binary);

	int input_x, input_y{ 0 };
	float input_ftime{ 0.0f };

	while (in >> input_x >> input_y >> input_ftime)
	{
		m_key.emplace_back(Key(input_x, input_y, input_ftime));
	}

	for (const auto& p : m_key)
		p.show();

	break;
	}

	case ID_40003: // 불러온거 시작하기
		if (m_gamestate == state::PlayRecord) break;
		m_time = 0;
		m_gamestate = state::PlayRecord;
		break; 
	case ID_40004: // 새로 리플레이 만들기
		if (m_gamestate == state::PlayRecord) break;
		m_time = 0;
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
	
}
