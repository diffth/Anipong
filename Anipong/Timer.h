#pragma once

#include <Windows.h>
#include "Bitmap.h"


class Timer : public BitMap
{
private:
	int m_nSec; //
	int m_nId;// timer bitmap id
	int m_nX;
	int m_nY;
	int m_nWidth;
	int m_nHeight;

public:
	Timer();
	~Timer() {};
public:
	void showTimerSec();
	void setId(int nId) { m_nId = nId; }
	void setCoord(int nX, int nY) { m_nX = nX; m_nY = nY; }
	void getCoord(int* nX, int* nY) { *nX = m_nX; *nY = m_nY; }
//	void setTimer(int nSec);
//	int getTimer();
};

