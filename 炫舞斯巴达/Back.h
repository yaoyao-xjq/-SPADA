#pragma once
#include "Sys.h"
#define FLYSTAR_NUMBER 100//粒子数量的宏
#define FLYSTAR_LASTED_FRAME 60//表示持续帧数的宏
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
//	int lasted;//存在的时间
//	BOOL exist;//星光是否存在
//};
class CBack
{
public:
	//FLYSTAR FlyStars[FLYSTAR_NUMBER];//粒子数组
	int g_StarNum;//计数
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

