#pragma once
#include "Arrow.h"
class CDownArrow :
	public CArrow
{
public:
	CDownArrow(void);
	~CDownArrow(void);
public:
	virtual void ArrowInit(HINSTANCE hIns,int x,int y);
	virtual void ArrowShow(HDC hMemDC);
	virtual void ChangeArrow();
};

