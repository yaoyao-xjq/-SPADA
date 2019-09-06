#pragma once
#include "Arrow.h"
class CRightArrow :
	public CArrow
{
public:
	CRightArrow(void);
	~CRightArrow(void);
public:
	virtual void ArrowInit(HINSTANCE hIns,int x,int y);
	virtual void ArrowShow(HDC hMemDC);
	virtual void ChangeArrow();
};

