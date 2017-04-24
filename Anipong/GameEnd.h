#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "resource.h"
#include "Bitmap.h"
using namespace std;



class GameEnd : public BitMap
{
private:
	int m_nId;					//프레임 id
	int m_nX, m_nY;				//좌표
	int m_nWidth, m_nHeight;	//가로/세로
	unsigned int m_nStatus;		//현재 상태

public:
	GameEnd();
	~GameEnd();

	void showBG();
	void showRestartButton();
	void showEndButton();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
};
