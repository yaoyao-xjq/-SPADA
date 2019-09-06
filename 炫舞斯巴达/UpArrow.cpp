#include "UpArrow.h"


CUpArrow::CUpArrow(void)
{
	m_hArrowWhite=0;
	m_hArrowBlack=0;
	m_hArrowWhitey=0;
	m_hArrowBlacky=0;
	ArrowStyle=1;
	point.x=0;
	point.y=0;
}


CUpArrow::~CUpArrow(void)
{
}
void CUpArrow::ArrowInit(HINSTANCE hIns,int x,int y)
{
	m_hArrowWhite=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WHITEUP));
	m_hArrowBlack=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BLACKUP));
	m_hArrowWhitey=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WHITEUPY));
	m_hArrowBlacky=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BLACKUPY));
	this->point.x=x;
	this->point.y=y;
}
void CUpArrow::ArrowShow(HDC hMemDC)
{
	HDC hFxDC=::CreateCompatibleDC(hMemDC);
	if(flag==false)
	{
		::SelectObject(hFxDC,m_hArrowWhite);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCAND);
		::SelectObject(hFxDC,m_hArrowBlack);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCPAINT);
	}
	else
	{
		::SelectObject(hFxDC,m_hArrowWhitey);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCAND);
		::SelectObject(hFxDC,m_hArrowBlacky);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCPAINT);
	
	}
	::DeleteDC(hFxDC);
}
void CUpArrow::ChangeArrow()
{
	flag=true;
}