#include <windows.h>   //  Window API 函数
#include <time.h>
#include "GameApp.h"
#include"Back.h"

PFUN_CREATE_OBJECT CGameApp::pfnCreateObject = 0;   //  static 成员的初始化

HINSTANCE  g_hIns = 0;
CGameApp* pCtrl = 0;

//  消息的处理函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_CREATE:
		if(CGameApp::pfnCreateObject == NULL)
		{
			::MessageBox(NULL,"游戏创建失败","提示",MB_OK);
			::DestroyWindow(hwnd);   //  销毁窗口
			::PostQuitMessage(0);    //  退出程序
			break;
		}
		//  创建游戏
		pCtrl = (*CGameApp::pfnCreateObject)();  //  创建  子类的游戏的对象
		//  设置句柄
		pCtrl->SetHandle(g_hIns,hwnd);
		//  初始化游戏
		pCtrl->OnCreateGame();
		break;
	case WM_PAINT:
		if(pCtrl != NULL)
			pCtrl->OnGameDraw();
		break;
	case WM_TIMER:
		if(pCtrl != NULL)
			pCtrl->OnGameRun(wParam);
		break;
	case WM_KEYDOWN:
		if(pCtrl != NULL)
			pCtrl->OnKeyDown(wParam);
		break;
	case WM_KEYUP:
		if(pCtrl != NULL)
			pCtrl->OnKeyUp(wParam);
		break;
	case WM_LBUTTONDOWN:
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			if(pCtrl != NULL)
				pCtrl->OnLButtonDown(point);
		}
		break;
	case WM_LBUTTONUP:
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			if(pCtrl != NULL)
				pCtrl->OnLButtonUp(point);
		}
		break;
	case WM_MOUSEMOVE:
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			if(pCtrl != NULL)
				pCtrl->OnMouseMove(point);
		}
		break;
	case WM_CLOSE:   //  关闭  要退出
		delete pCtrl;
		pCtrl = NULL;
		::PostQuitMessage(0);   //  发送一个退出的消息
		break;
	}
	return ::DefWindowProc(hwnd,uMsg,wParam,lParam);   //  默认处理消息
}


int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	g_hIns = hInstance;
	srand((unsigned int)time(0));


	HBRUSH hBrush = ::CreateSolidBrush(RGB(155,99,14));  //  创建画刷
	//  设计窗口  12
 	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.hbrBackground = hBrush;
	wndclass.hCursor = 0;
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.lpszClassName = "哈哈";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_VREDRAW|CS_HREDRAW;

	//  注册
	if(!::RegisterClassEx(&wndclass))
	{
		::MessageBox(NULL,"注册失败","提示",MB_OK);
		return 0;
	}

	//  创建
	HWND hwnd = ::CreateWindow("哈哈","炫舞ing---",WS_OVERLAPPEDWINDOW,0,0,770,585,0,0,hInstance,0);
	if(hwnd == NULL)
	{
		::MessageBox(NULL,"创建失败","提示",MB_OK);
		return 0;
	}
	
	//  显示
	::ShowWindow(hwnd,SW_SHOW);
	
	//  消息循环
	MSG msg;  //  装消息的结构体
	while(::GetMessage(&msg,0,0,0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);   //  掉用消息函数  处理消息
	}
	::DeleteObject(hBrush);   //  删除这个画刷
	return 0;
}