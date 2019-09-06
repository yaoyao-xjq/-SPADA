#pragma once
#include "gameapp.h"
#include "Back.h"
#include "Arrow.h"
#include "LeftArrow.h "
#include "RightArrow.h "
#include "UpArrow.h "
#include "DownArrow.h "

class CDanceApp :
	public CGameApp
{
public:
	DECLARE()
public:
	CBack back;
	HDC dc;
	HDC hMemDC;
	HBITMAP hBitMap;
	
public:
	list<CArrow*> m_lstArrow;
	
public:
	CDanceApp(void);
	~CDanceApp(void);
public:
	void OnCreateGame();    //WM_CREATE  初始化游戏，加载资源
	void OnGameDraw();      //WM_PAINT
	void OnGameRun(WPARAM nTimerID);     //WM_TIMER
	void OnKeyDown(WPARAM nKey);      //WM_KEYDOWN
	void CreateArrow(int x,int y);
	void AllArrowShow();
	virtual void OnLButtonDown(POINT point);
};

