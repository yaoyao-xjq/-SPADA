#pragma once
#include "Arrow.h"
class CUpArrow :
	public CArrow
{
public:
	CUpArrow(void);
	~CUpArrow(void);
public:
	virtual void ArrowInit(HINSTANCE hIns,int x,int y);
	virtual void ArrowShow(HDC hMemDC);
	virtual void ChangeArrow();
};

