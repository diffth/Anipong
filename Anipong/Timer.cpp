#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Timer.h"
#include "Common.h"

#include "resource.h"
#include "Bitmap.h"

Timer tsArr[60];// timer�� �迭

extern bool timeOut;
HANDLE hTimeOutEvent;

Timer::Timer() : BitMap(SEC_FRAME)
{
	m_nId = SEC_FRAME;		//������ bitmap id
	m_nX = SEC_START_X;
	m_nY = SEC_START_Y;
	m_nWidth = SEC_WIDTH;
	m_nHeight = SEC_HEIGHT;	//����/����

}

//Timer ó�� Thread
unsigned int CALLBACK ThreadTimer(void* arg)
{
	int i = TIMER_COL;
	while (i)
	{
		tsArr[i - 1].setId(SEC_EMPTY);
		tsArr[i - 1].showTimerSec();

		Sleep(1000);
		i--;
	}

	SetEvent(hTimeOutEvent);
	return 0;
}

void Timer::showTimerSec()
{
	showBitmap(m_nX, m_nY, SEC_WIDTH, SEC_HEIGHT, m_nId);
}


//void Timer::setTimer(int nSec)// Timer�� �ð��� �����ϴ� �Լ�
//{
//	m_nSec = nSec;
//}
//
//int Timer::getTimer()
//{
//	return m_nSec;
//}