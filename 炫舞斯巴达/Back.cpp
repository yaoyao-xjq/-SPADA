#include "Back.h"
#include"resource.h"
#include"DanceApp.h"
CBack::CBack(void)
{
	g_StarNum=0;
	m_hBmpBack1=0;
	m_hBmpBack2=0;
	m_hBmpBack3=0;
	m_hBmpBackLeft=0;
	m_hBmpBackRight=0;
	point.x=-PICTURE_LENGTH;
	point.y=0;
	
}
int CBack::bj1=0;
int CBack::bj2=0;

CBack::~CBack(void)
{
	DeleteObject(m_hBmpBack1);
	DeleteObject(m_hBmpBack2);
	DeleteObject(m_hBmpBack3);
	DeleteObject(m_hBmpBackLeft);
	DeleteObject(m_hBmpBackRight);
	m_hBmpBack1=0;
	m_hBmpBack2=0;
	m_hBmpBack3=0;
	m_hBmpBackLeft=0;
	m_hBmpBackRight=0;
}
void CBack::BackInit(HINSTANCE hIns)
{
	m_hBmpBack1=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BITMAPxin1));
	m_hBmpBack2=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BITMAPxin2));
	m_hBmpBack3=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BITMAP3));
	m_hBmpBackLeft=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BITMAPleft));
	m_hBmpBackRight=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BITMAPright));
	//*********ÐÇÐÇÍ¼Æ¬
//m_hStar=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_backgroungright));
}
void CBack::BackShow(HDC hMemDC)
{
	/*if(g_StarNum==0)
	{
	     int x=rand()%WINDOW_LENGTH;
		 int y=rand()%WINDOW_HEIGTH;
		 for(int i=0;i<FLYSTAR_NUMBER;i++)
		 {
		    FlyStars[i].x=x;
			FlyStars[i].y=y;
			FlyStars[i].lasted=0;
			if(i%4==0)
			{
			    FlyStars[i].vx=-(1+rand()%15);
				FlyStars[i].vy=-(1+rand()%15);
			}
			
			if(i%4==1)
			{
			    FlyStars[i].vx=(1+rand()%15);
				FlyStars[i].vy=(1+rand()%15);
			}
			if(i%4==2)
			{
			    FlyStars[i].vx=-(1+rand()%15);
				FlyStars[i].vy=(1+rand()%15);
			}
			if(i%4==3)
			{
			    FlyStars[i].vx=(1+rand()%15);
				FlyStars[i].vy=-(1+rand()%15);
			}
			
			FlyStars[i].exist=true;
		 
		 }
		 g_StarNum=FLYSTAR_NUMBER;
	}
	
	for(int i=0;i<FLYSTAR_NUMBER;i++)
	{
		
	     if(FlyStars[i].exist)
		 {
			
			 SelectObject( hTempDC,m_hStar);
			 TransparentBlt(hMemDC,FlyStars[i].x,FlyStars[i].y,30,30,hTempDC,0,0,30,30,RGB(0,0,0));
		     FlyStars[i].x+=FlyStars[i].vx;
			 FlyStars[i].y+=FlyStars[i].vy;
			 FlyStars[i].lasted++;
			 if(FlyStars[i].x<0||FlyStars[i].x>WINDOW_LENGTH||FlyStars[i].y<0||FlyStars[i].y>WINDOW_HEIGTH||FlyStars[i].lasted>FLYSTAR_LASTED_FRAME)
			 {
				 FlyStars[i].exist=false;
				 g_StarNum--;
			 }
		 }
	
	}*/
	 HDC hTempDC = ::CreateCompatibleDC(hMemDC);
	BitBlt(hMemDC,0,0,WINDOW_HEIGTH,WINDOW_LENGTH,hTempDC,0,0,SRCCOPY);
	
	if(bj1 == 0)
	{
		HDC hTempDC = ::CreateCompatibleDC(hMemDC);
		::SelectObject(hTempDC,m_hBmpBack1);
		::BitBlt(hMemDC,0,0,PICTURE_LENGTH,PICTURE_HEIGHT,hTempDC,0,0,SRCCOPY);
		DeleteDC(hTempDC);
	}
    if (bj1 == 1)
	{
		HDC hTempDC = ::CreateCompatibleDC(hMemDC);
		::SelectObject(hTempDC,m_hBmpBack2);
		::BitBlt(hMemDC,0,0,PICTURE_LENGTH,PICTURE_HEIGHT,hTempDC,0,0,SRCCOPY);
		DeleteDC(hTempDC);
	}
	//left,right;
    if(bj1==1&&bj2 ==1)
	{
	   HDC hBackDC=::CreateCompatibleDC(hMemDC);
	::SelectObject(hBackDC,m_hBmpBackLeft);
	::BitBlt(hMemDC,point.x,point.y,PICTURE_LENGTH,PICTURE_HEIGHT,hBackDC,0,0,SRCCOPY);
	::SelectObject(hBackDC,m_hBmpBackRight);
	::BitBlt(hMemDC,point.x+PICTURE_LENGTH,point.y,PICTURE_LENGTH,PICTURE_HEIGHT,hBackDC,0,0,SRCCOPY);
	::DeleteDC(hBackDC);
	}

	else if(bj1==1&&bj2 ==2)
	{
	    HDC hBackDC=::CreateCompatibleDC(hMemDC);
	::SelectObject(hBackDC,m_hBmpBackLeft);
	::BitBlt(hMemDC,point.x,point.y,PICTURE_LENGTH,PICTURE_HEIGHT,hBackDC,0,0,SRCCOPY);
	::SelectObject(hBackDC,m_hBmpBackRight);
	::BitBlt(hMemDC,point.x+PICTURE_LENGTH,point.y,PICTURE_LENGTH,PICTURE_HEIGHT,hBackDC,0,0,SRCCOPY);
	::DeleteDC(hBackDC);
	}

	
}
void CBack::BackMove()
{
	if(point.x== PICTURE_LENGTH)
		point.x = 0;
	else
		point.x++;
}
void CBack::BackChange()
{
	bj1++;
	
}