#pragma once
#include "Arrow.h"
class CLeftArrow :
	public CArrow
{
public:
	CLeftArrow(void);
	~CLeftArrow(void);
public:
	virtual void ArrowInit(HINSTANCE hIns,int x,int y);
	virtual void ArrowShow(HDC hMemDC);
	virtual void ChangeArrow();
};
