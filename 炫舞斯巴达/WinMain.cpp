#include <windows.h>   //  Window API ����
#include <time.h>
#include "GameApp.h"
#include"Back.h"

PFUN_CREATE_OBJECT CGameApp::pfnCreateObject = 0;   //  static ��Ա�ĳ�ʼ��

HINSTANCE  g_hIns = 0;
CGameApp* pCtrl = 0;

//  ��Ϣ�Ĵ�����
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_CREATE:
		if(CGameApp::pfnCreateObject == NULL)
		{
			::MessageBox(NULL,"��Ϸ����ʧ��","��ʾ",MB_OK);
			::DestroyWindow(hwnd);   //  ���ٴ���
			::PostQuitMessage(0);    //  �˳�����
			break;
		}
		//  ������Ϸ
		pCtrl = (*CGameApp::pfnCreateObject)();  //  ����  �������Ϸ�Ķ���
		//  ���þ��
		pCtrl->SetHandle(g_hIns,hwnd);
		//  ��ʼ����Ϸ
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
	case WM_CLOSE:   //  �ر�  Ҫ�˳�
		delete pCtrl;
		pCtrl = NULL;
		::PostQuitMessage(0);   //  ����һ���˳�����Ϣ
		break;
	}
	return ::DefWindowProc(hwnd,uMsg,wParam,lParam);   //  Ĭ�ϴ�����Ϣ
}


int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	g_hIns = hInstance;
	srand((unsigned int)time(0));


	HBRUSH hBrush = ::CreateSolidBrush(RGB(155,99,14));  //  ������ˢ
	//  ��ƴ���  12
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
	wndclass.lpszClassName = "����";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_VREDRAW|CS_HREDRAW;

	//  ע��
	if(!::RegisterClassEx(&wndclass))
	{
		::MessageBox(NULL,"ע��ʧ��","��ʾ",MB_OK);
		return 0;
	}

	//  ����
	HWND hwnd = ::CreateWindow("����","����ing---",WS_OVERLAPPEDWINDOW,0,0,770,585,0,0,hInstance,0);
	if(hwnd == NULL)
	{
		::MessageBox(NULL,"����ʧ��","��ʾ",MB_OK);
		return 0;
	}
	
	//  ��ʾ
	::ShowWindow(hwnd,SW_SHOW);
	
	//  ��Ϣѭ��
	MSG msg;  //  װ��Ϣ�Ľṹ��
	while(::GetMessage(&msg,0,0,0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);   //  ������Ϣ����  ������Ϣ
	}
	::DeleteObject(hBrush);   //  ɾ�������ˢ
	return 0;
}