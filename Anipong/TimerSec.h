#pragma once
#include <Windows.h>
#include "resource.h"
#include "Common.h"
#include "Bitmap.h"

using namespace std;

class TimerSec : public BitMap
{
private:
	int m_nId;
	int m_nX, m_nY;				//��ǥ
//	int m_nWidth, m_nHeight;	//����/����
	int m_nSec;

public:
	TimerSec();
	~TimerSec();

public:
	void showTimerSec();
	void setId(int nId);
	void setX(int nX);
	void setY(int nY);
	int getId();
	int getX();
	int getY();
};
