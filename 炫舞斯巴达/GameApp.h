#pragma once 

#ifndef _GAMEAPP_H_
#define _GAMEAPP_H_

#include <windows.h>

//  定义函数指针的类型
class CGameApp;   //  前向声明
typedef CGameApp* (*PFUN_CREATE_OBJECT)();

#define DECLARE() static CGameApp* CreateObject();

#define IMPLEMENT(ThisClass) \
	CGameApp* ThisClass::CreateObject()\
	{\
		return new ThisClass;\
	}\
	Init init##ThisClass(&ThisClass::CreateObject);


class CGameApp
{
public:
	static PFUN_CREATE_OBJECT pfnCreateObject;    // 创建对象的函数指针变量
protected:
	HINSTANCE m_hIns;
	HWND m_hMainWnd;            //   主窗口
public:
	CGameApp()
	{
		m_hIns = 0;
		m_hMainWnd = 0;
	}
	virtual ~CGameApp()
	{
	
	}
public:
	void SetHandle(HINSTANCE hIns,HWND hwnd)
	{
		this->m_hIns = hIns;
		this->m_hMainWnd = hwnd;
	}
public:
	virtual void OnCreateGame(){}    //WM_CREATE  初始化游戏，加载资源
	virtual void OnGameDraw(){}      //WM_PAINT
	virtual void OnGameRun(WPARAM nTimerID){}      //WM_TIMER
	virtual void OnKeyDown(WPARAM nKey){}      //WM_KEYDOWN
	virtual void OnKeyUp(WPARAM nKey){}        //WM_KEYUP
	virtual void OnLButtonDown(POINT point){}   //WM_LBUTTONDOWN
	virtual void OnLButtonUp(POINT point){}   //WM_LBUTTONUP
	virtual void OnMouseMove(POINT point){}   //WM_MOUSEMOVE
};


class Init
{
public:
	Init(PFUN_CREATE_OBJECT pfn)    //  通过这类型构造函数  给 函数指针重新赋值
	{
		CGameApp::pfnCreateObject = pfn;
	}
};


#endif//_GAMEAPP_H_
