#include "DownArrow.h"


CDownArrow::CDownArrow(void)
{
	m_hArrowWhite=0;
	m_hArrowBlack=0;
	m_hArrowWhitey=0;
	m_hArrowBlacky=0;
	ArrowStyle=2;
	point.x=0;
	point.y=0;
}


CDownArrow::~CDownArrow(void)
{
}
void CDownArrow::ArrowInit(HINSTANCE hIns,int x,int y)
{
	m_hArrowWhite=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WHITEDOWN));
	m_hArrowBlack=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BLACKDOWN));
	m_hArrowWhitey=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WHITEDOWNY));
	m_hArrowBlacky=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BLACKDOWNY));
	this->point.x=x;
	this->point.y=y;
}
void CDownArrow::ArrowShow(HDC hMemDC)
{
	HDC hFxDC=::CreateCompatibleDC(hMemDC);
	if(flag==false)//如果标记为false 贴正常图
	{
		::SelectObject(hFxDC,m_hArrowWhite);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCAND);
		::SelectObject(hFxDC,m_hArrowBlack);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCPAINT);
	}
	else//如果标记为false 贴黄色的图
	{
		::SelectObject(hFxDC,m_hArrowWhitey);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCAND);
		::SelectObject(hFxDC,m_hArrowBlacky);
		::BitBlt(hMemDC,point.x,point.y,50,50,hFxDC,0,0,SRCPAINT);
	}
	::DeleteDC(hFxDC);
}
void CDownArrow::ChangeArrow()
{
	flag=true;
}