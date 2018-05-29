#pragma once
#include "operator.h"
#include "Point.h"
class CGameObject
{
protected:
	RECT m_rcobjsize;
	Point m_ptpos;
	float m_fsizerate;

public:
	CGameObject();
	virtual ~CGameObject();

	virtual void draw(HDC hdc) = 0;
	void Setsizerate(const float& q) { m_fsizerate = q; }
	const float Getsizerate() { return m_fsizerate; }

	void SetObjRECT(const RECT& q) { m_rcobjsize = q; }

	//GetRECTsize: sizerate가 적용된 오브젝트 사이즈
	const RECT GetRECTsize() const { return m_rcobjsize*m_fsizerate; }

	//GetObjRECT: pos가 적용된 
	const RECT GetObjRECT() const { return GetRECTsize() + m_ptpos.GetPOINT(); }


	void SetPos(const Point& q) { m_ptpos = q; }
	const Point Getpos()const { return m_ptpos; }
	Point * Getposptr() { return &m_ptpos; }

	bool BoxCollision_posconst(const RECT& rcObj);

};

