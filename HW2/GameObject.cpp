#include "header.h"
#include "GameObject.h"
#include "BitmapObject.h"


CGameObject::CGameObject() :m_fsizerate(1.f)
{
}

bool CGameObject::BoxCollision_posconst(const RECT & rcObj)
{
	RECT temp = GetObjRECT();
	if (temp.left		<		rcObj.right		&&
		temp.right		>		rcObj.left		&&
		temp.top		<		rcObj.bottom	&&
		temp.bottom		>		rcObj.top) {

		return true;
	}
	return false;
}

CGameObject::~CGameObject()
{
}
