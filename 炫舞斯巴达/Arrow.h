#pragma once
#include"Sys.h"
class CArrow
{
public:
	HBITMAP m_hArrowWhite;
	HBITMAP m_hArrowBlack;
	HBITMAP m_hArrowWhitey;
	HBITMAP m_hArrowBlacky;
	POINT point;
public:
	int ArrowStyle;
	bool flag;
public:
	CArrow(void);
	~CArrow(void);
public:
	virtual void ArrowInit(HINSTANCE hIns,int x,int y)=0;
	virtual void ArrowShow(HDC hMemDC)=0;
	virtual void ChangeArrow() = 0;
};

