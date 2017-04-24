#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "Timer.h"
#include "Common.h"

#include "resource.h"
#include "Bitmap.h"

Timer tsArr[60];// timer용 배열

extern bool timeOut;
HANDLE hTimeOutEvent;

Timer::Timer() : BitMap(SEC_FRAME)
{
	m_nId = SEC_FRAME;		//프레임 bitmap id
	m_nX = SEC_START_X;
	m_nY = SEC_START_Y;
	m_nWidth = SEC_WIDTH;
	m_nHeight = SEC_HEIGHT;	//가로/세로

}

//Timer 처리 Thread
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


//void Timer::setTimer(int nSec)// Timer의 시간을 세팅하는 함수
//{
//	m_nSec = nSec;
//}
//
//int Timer::getTimer()
//{
//	return m_nSec;
//}