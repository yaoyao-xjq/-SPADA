#pragma once
#include "Sys.h"
#define FLYSTAR_NUMBER 100//���������ĺ�
#define FLYSTAR_LASTED_FRAME 60//��ʾ����֡���ĺ�
#define WINDOW_LENGTH 873
#define WINDOW_HEIGTH 623
#define PICTURE_LENGTH 856
#define PICTURE_HEIGHT 583

//struct FLYSTAR
//{
//    int x;
//	int y;
//	int vx;
//	int vy;
//	int lasted;//���ڵ�ʱ��
//	BOOL exist;//�ǹ��Ƿ����
//};
class CBack
{
public:
	//FLYSTAR FlyStars[FLYSTAR_NUMBER];//��������
	int g_StarNum;//����
	HBITMAP m_hBmpBack1;
	HBITMAP m_hBmpBack2;
	HBITMAP m_hBmpBack3;
	HBITMAP m_hBmpBackLeft;
	HBITMAP m_hBmpBackRight;
	HBITMAP m_hStar;;
	POINT point;
	static int bj1;
    static int  bj2;
public:
	CBack(void);
	~CBack(void);
public:
	void BackInit(HINSTANCE hIns);
	void BackShow(HDC hMemDC);
	void BackMove();
	void BackChange();
};

