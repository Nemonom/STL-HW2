#pragma once
#include "GameObject.h"
#include <atlimage.h>
class CBitmapObject :
	public CGameObject
{
protected:
	CImage m_cimg;

	POINT m_bmpsize;

	COLORREF m_delRGB;
	bool m_isBMP;
public:
	CBitmapObject();
	~CBitmapObject();

	void releaseCimg() {
		m_cimg.Destroy();
	}
	void loadCimg(const LPCTSTR& pStream) {
		m_cimg.Load(pStream);
		if (m_cimg.IsNull()) {
			m_cimg.Load(L"Resorce/Menu/button.png");
			m_isBMP = false;

		}
	}

	void OnCreatCimg(const LPCTSTR& pStream) {

		CString strResult = PathFindExtension(pStream);
		if (!lstrcmp(strResult.GetString(),L".bmp")) {
			m_isBMP = true;
		}

		m_cimg.Load(pStream);

		if (m_cimg.IsNull()) {
			m_cimg.Load(L"Resorce/Menu/button.png");
			m_isBMP = false;

		}
			//nullimg.bmp

		m_bmpsize.x = m_cimg.GetWidth();
		m_bmpsize.y = m_cimg.GetHeight();
		m_rcobjsize = RECT{ 0,0,m_bmpsize.x,m_bmpsize.y };
//		m_ptpos = Point{ m_bmpsize.x / 2,m_bmpsize.y / 2 };
//		m_rcobjsize -= m_ptpos.GetPOINT();

		if (!m_isBMP) {

			if (m_cimg.GetBPP() == 32)
			{
				unsigned char * pCol = 0;
				long w = m_bmpsize.x;
				long h = m_bmpsize.y;
				for (long y = 0; y < h; y++)
				{
					for (long x = 0; x < w; x++)
					{
						pCol = (unsigned char *)m_cimg.GetPixelAddress(x, y);
						unsigned char alpha = pCol[3];
						if (alpha != 255)
						{
							pCol[0] = ((pCol[0] * alpha) + 128) >> 8;
							pCol[1] = ((pCol[1] * alpha) + 128) >> 8;
							pCol[2] = ((pCol[2] * alpha) + 128) >> 8;
						}
					}
				}
				m_cimg.SetHasAlphaChannel(true);
			}
		}
		

	}
	void drawalpha(HDC hdc, BYTE  ifalpha);
	virtual void draw(HDC hdc) override;
	void draw(HDC hdc, RECT rectDest);

	void draw(HDC hdc, RECT rectDest, float rot);
	void draw(HDC hdc, POINT ptPivot, float rot);
	void draw(HDC hdc, POINT* inarr);

	void Setmidpos(const RECT& rc) {


		m_ptpos = Point{ m_bmpsize.x / 2,m_bmpsize.y / 2 };
		m_rcobjsize -= m_ptpos.GetPOINT();
		m_ptpos = Point{ (rc.right + rc.left) / 2,(rc.top + rc.bottom) / 2 };
	//	m_rcobjsize = RECT{ 0,0,m_bmpsize.x,m_bmpsize.y };
		
	}

	void NewFunction(RECT rcSorce, POINT  *arr, const float& fradian);

};

