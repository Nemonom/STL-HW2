#include "header.h"
#include "BitmapObject.h"


CBitmapObject::CBitmapObject()
{
	m_delRGB = RGB(255, 0, 255);
	m_isBMP = false;
}


CBitmapObject::~CBitmapObject()
{
	m_cimg.Destroy();//명시적해제
}

void CBitmapObject::drawalpha(HDC hdc, BYTE ifalpha)
{

	RECT rctmp = GetObjRECT();
	RECT rcrsc{ 0,0,m_bmpsize.x,m_bmpsize.y };

	m_cimg.AlphaBlend(hdc, rctmp,rcrsc, ifalpha,0);

}

void CBitmapObject::draw(HDC hdc)
{

	RECT rctmp = GetObjRECT();
	if (m_isBMP) {
		m_cimg.TransparentBlt(hdc, rctmp, m_delRGB);
	}
	else {

	m_cimg.Draw(hdc, rctmp);
	}
}

void CBitmapObject::draw(HDC hdc, RECT rectDest)
{
	if (m_isBMP) {
		m_cimg.TransparentBlt(hdc, rectDest, m_delRGB);
	}
	else {

		m_cimg.Draw(hdc, rectDest);
	}
}




void CBitmapObject::draw(HDC hdc,RECT rectDest, float fradian)
{
	RECT rcSorce = rectDest;
	POINT arr[3];
	NewFunction(rcSorce, arr, fradian);
	if (m_isBMP) {
		HDC transhdc = CreateCompatibleDC(hdc);
		HBITMAP transhbmp = CreateCompatibleBitmap(hdc, WIDTH, HEIGHT);
		HBITMAP oldbmp = (HBITMAP)SelectObject(transhdc, transhbmp);
		HBRUSH ff00ffbr = CreateSolidBrush(m_delRGB);
		HBRUSH oldbr = (HBRUSH)SelectObject(transhdc, ff00ffbr);

		RECT tmp{ 0,0, WIDTH, HEIGHT };

		FillRect(transhdc, &tmp, ff00ffbr);
		m_cimg.PlgBlt(transhdc, arr);
		TransparentBlt(hdc, 0, 0, WIDTH, HEIGHT, transhdc, 0, 0, WIDTH, HEIGHT, m_delRGB);


		SelectObject(transhdc, oldbmp);
		SelectObject(transhdc, oldbr);
		DeleteObject(ff00ffbr);
		DeleteObject(transhbmp);
		DeleteDC(transhdc);
		//		m_cimg.TransparentBlt(hdc,)
		return;
	}
}

void CBitmapObject::draw(HDC hdc, POINT ptPivot, float rot)
{
	RECT rcSorce = GetObjRECT();
	POINT arr[3];
	NewFunction(rcSorce, arr, rot);

	for (int i = 0; i < 3; i++) {
		arr[i] = arr[i] + ptPivot;
	}
	if (m_isBMP) {
		HDC transhdc = CreateCompatibleDC(hdc);
		HBITMAP transhbmp = CreateCompatibleBitmap(hdc, WIDTH, HEIGHT);
		HBITMAP oldbmp = (HBITMAP)SelectObject(transhdc, transhbmp);
		HBRUSH ff00ffbr = CreateSolidBrush(m_delRGB);
		HBRUSH oldbr = (HBRUSH)SelectObject(transhdc, ff00ffbr);

		RECT tmp{ 0,0, WIDTH, HEIGHT };

		FillRect(transhdc, &tmp, ff00ffbr);
		m_cimg.PlgBlt(transhdc, arr);
		TransparentBlt(hdc, 0, 0, WIDTH, HEIGHT, transhdc, 0, 0, WIDTH, HEIGHT, m_delRGB);


		SelectObject(transhdc, oldbmp);
		SelectObject(transhdc, oldbr);
		DeleteObject(ff00ffbr);
		DeleteObject(transhbmp);
		DeleteDC(transhdc);
		//		m_cimg.TransparentBlt(hdc,)
		return;
	}
}

void CBitmapObject::draw(HDC hdc, POINT* inarr)
{
	RECT rcSorce = GetObjRECT();
	POINT arr[3];
	for (int i = 0; i < 3; i++) {
		arr[i] = inarr[i];
	}
	if (m_isBMP) {
		HDC transhdc = CreateCompatibleDC(hdc);
		HBITMAP transhbmp = CreateCompatibleBitmap(hdc, WIDTH, HEIGHT);
		HBITMAP oldbmp = (HBITMAP)SelectObject(transhdc, transhbmp);
		HBRUSH ff00ffbr = CreateSolidBrush(m_delRGB);
		HBRUSH oldbr = (HBRUSH)SelectObject(transhdc, ff00ffbr);

		RECT tmp{ 0,0, WIDTH, HEIGHT };

		FillRect(transhdc, &tmp, ff00ffbr);
		m_cimg.PlgBlt(transhdc, arr);
		TransparentBlt(hdc, 0, 0, WIDTH, HEIGHT, transhdc, 0, 0, WIDTH, HEIGHT, m_delRGB);


		SelectObject(transhdc, oldbmp);
		SelectObject(transhdc, oldbr);
		DeleteObject(ff00ffbr);
		DeleteObject(transhbmp);
		DeleteDC(transhdc);
		//		m_cimg.TransparentBlt(hdc,)
		return;
	}
}

void CBitmapObject::NewFunction(RECT rcSorce, POINT * arr, const float & fradian)
{

	POINT ptsorcepos{ rcSorce.right + rcSorce.left
		,rcSorce.bottom + rcSorce.top };
	ptsorcepos.x /= 2;
	ptsorcepos.y /= 2;
	rcSorce.left -= ptsorcepos.x;
	rcSorce.right -= ptsorcepos.x;
	rcSorce.top -= ptsorcepos.y;
	rcSorce.bottom -= ptsorcepos.y;

	arr[0] = POINT{ rcSorce.left,rcSorce.top };
	arr[1] = POINT{ rcSorce.right,rcSorce.top };
	arr[2] = POINT{ rcSorce.left,rcSorce.bottom };

	float cosx = cos(fradian);
	float sinx = sin(fradian);
	for (int i = 0; i < 3; i++) {
		auto tmp = arr[i];
		arr[i].x = tmp.x*cosx + tmp.y*sinx;
		arr[i].y = -tmp.x*sinx + tmp.y*cosx;
	}

	for (int i = 0; i < 3; i++) {
		arr[i] = arr[i] + ptsorcepos;
	}
}
