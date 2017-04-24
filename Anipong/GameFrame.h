#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "resource.h"
#include "Common.h"
#include "Bitmap.h"

using namespace std;

class GameFrame : public BitMap
{
private:
	int m_nId;					//프레임
	int m_nX, m_nY;				//좌표
	int m_nWidth, m_nHeight;	//가로/세로
	unsigned int m_nStatus;		//현재 상태

public:
	GameFrame();
	~GameFrame();

	void showFrame();
	void getCoord();
	void setCoord();
	void getSize(int nWidth);
	void setSize(int nHeight);
	void getTime();
	void setTime();

//	void SetCursorShow(int nV);
	
};

