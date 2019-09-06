#include "DanceApp.h"
#include"Back.h"
#include"Sys.h"
IMPLEMENT(CDanceApp)
list<CArrow*>::iterator iteArrow;
CDanceApp::CDanceApp(void)
{
	dc=0;
	hMemDC=0;
	hBitMap=0;
	
}


CDanceApp::~CDanceApp(void)
{
	::DeleteObject(hBitMap);
	::DeleteDC(hMemDC);
	::ReleaseDC(m_hMainWnd,dc);
	//list<CArrow*>::iterator ite=m_lstArrow.begin();
	//while(ite!=m_lstArrow.end())
	//{
	//	delete (*ite);
	//	++ite;
	//}
}
void CDanceApp::OnCreateGame()
{
	dc=::GetDC(m_hMainWnd);
	hMemDC=::CreateCompatibleDC(dc);
	hBitMap=::CreateCompatibleBitmap(dc,PICTURE_LENGTH,PICTURE_HEIGHT);
	::SelectObject(hMemDC,hBitMap);
	//初始化背景
	back.BackInit(m_hIns);
	
	
	  
	
	
	//初始化箭头
	
	   this->CreateArrow(300,400);
	
	
	iteArrow=m_lstArrow.begin();
	//启动定时器
	 ::SetTimer(m_hMainWnd,BACK_MOVE_TIME_ID,50,NULL);  
}
void CDanceApp::OnGameDraw()
{
	//显示背景
	//HDC dc=::GetDC(m_hMainWnd);
	//HDC hMemDC=::CreateCompatibleDC(dc);
	//HBITMAP hBitMap=::CreateCompatibleBitmap(dc,750,550);
	//::SelectObject(hMemDC,hBitMap);
	//---------------------
	back.BackShow(hMemDC);
	if(CBack::bj2==1||CBack::bj2==2)
	{
	this->AllArrowShow();
	}
	
	//----------------------
	::BitBlt(dc,0,0,PICTURE_LENGTH,PICTURE_HEIGHT,hMemDC,0,0,SRCCOPY);
	//::DeleteObject(hBitMap);
	//::DeleteDC(hMemDC);
	//::ReleaseDC(m_hMainWnd,dc);
}
void CDanceApp::OnGameRun(WPARAM nTimerID)
{
	if((nTimerID == BACK_MOVE_TIME_ID&&CBack::bj2==1)||(nTimerID == BACK_MOVE_TIME_ID&&CBack::bj2==2))  
	{
		back.BackMove();
	}

	this->OnGameDraw();
}

void CDanceApp::OnKeyDown(WPARAM nKey)
{
		
		if(iteArrow!=m_lstArrow.end()&&nKey==VK_UP&&(*iteArrow)->ArrowStyle==1)
		{
			if((*iteArrow)->flag==false)
			{ 
				(*iteArrow)->ChangeArrow();
				iteArrow++;
			}
		}
		else if(iteArrow!=m_lstArrow.end()&&nKey==VK_DOWN&&(*iteArrow)->ArrowStyle==2)
		{
			if((*iteArrow)->flag==false)
			{
				(*iteArrow)->ChangeArrow();
				iteArrow++;
			}
		}
		else if(iteArrow!=m_lstArrow.end()&&nKey==VK_LEFT&&(*iteArrow)->ArrowStyle==3)
		{
			if((*iteArrow)->flag==false)
			{
				(*iteArrow)->ChangeArrow();
				iteArrow++;
			}
		
		}
		else if(iteArrow!=m_lstArrow.end()&&nKey==VK_RIGHT&&(*iteArrow)->ArrowStyle==4)
		{
			if((*iteArrow)->flag==false)
			{
				(*iteArrow)->ChangeArrow();
				iteArrow++;
			}
		}
		else if(iteArrow==(--m_lstArrow.end()))
		{
			list<CArrow*>::iterator iteArrowDel=m_lstArrow.begin();
			list<CArrow*>::iterator iteArrowTemp;
			while(iteArrowDel!=m_lstArrow.end())
			{
				iteArrowTemp=iteArrowDel;
				iteArrowDel++;
				delete (*iteArrowTemp);
				this->m_lstArrow.erase(iteArrowTemp);
				
				
			}
			this->CreateArrow(300,400);
			iteArrow=m_lstArrow.begin();
		}
		else
		{
			list<CArrow*>::iterator iteArrowDel=m_lstArrow.begin();
			list<CArrow*>::iterator iteArrowTemp;
			while(iteArrowDel!=m_lstArrow.end())
			{
				iteArrowTemp=iteArrowDel;
				iteArrowDel++;
				delete (*iteArrowTemp);
				this->m_lstArrow.erase(iteArrowTemp);
				
				
			}
			this->CreateArrow(300,400);
			iteArrow=m_lstArrow.begin();
		}

	this->OnGameDraw();
}
void CDanceApp::CreateArrow(int x,int y)
{
	for(int i=0;i<rand()%5+1;i++)//随机创建1-6个箭头
	{
		CArrow* pArrow=NULL;
		//创建箭头的对象
		int num=rand()%12;
		if(num>=0&&num<=3)
		{
			pArrow=new CLeftArrow;
		}
		else if(num>=4&&num<=6)
		{
			pArrow=new CRightArrow;
		}
		else if(num>=6&&num<=9)
		{
			pArrow=new CDownArrow;
		}
		else
		{
			pArrow=new CUpArrow;
		}
		//调用箭头的初始化
		pArrow->ArrowInit(m_hIns,x,y);
		//装入箭头的链表
		m_lstArrow.push_back(pArrow);
		x+=50;
	}
}
void CDanceApp::AllArrowShow()
{
	for (auto iteArrow:m_lstArrow)
		iteArrow->ArrowShow(hMemDC);
}
void CDanceApp::OnLButtonDown(POINT point)
{
	
	if(point.x>=696&&point.x<=820&&point.y>=425&&point.y<=484)
	{
			back.BackChange();
			
        	this->OnGameDraw();
	}
	if(CBack::bj1==1&&point.x>=281&&point.x<=362&&point.y>=310&&point.y<=435)
	{
	  CBack::bj2=1;
	  
	   this->OnGameDraw();
	}
	if(CBack::bj1==1&&point.x>=580&&point.x<=686&&point.y>=341&&point.y<=461)
	{
	   
	  CBack::bj2=2;
	   this->OnGameDraw();
	
	}
}