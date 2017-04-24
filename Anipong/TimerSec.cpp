#include <Windows.h>
#include "Common.h"
#include "TimerSec.h"

TimerSec::TimerSec() : BitMap(SEC_FRAME)
{
	m_nId		= SEC_FRAME;
	m_nX		= SEC_START_X;
	m_nY		= SEC_START_Y;
	//m_nWidth	= SEC_WIDTH;
	//m_nHeight	= SEC_HEIGHT;
}
TimerSec::~TimerSec()
{
}

void TimerSec::setId(int nId)
{
	m_nId = nId;
}

void TimerSec::showTimerSec()
{
	//for (int i = 0; i<60; i++)
	//	showBitmap(SEC_START_X + (i * 3), SEC_START_Y, SEC_WIDTH, SEC_HEIGHT, SEC_FRAME);
	showBitmap(SEC_START_X, SEC_START_Y, SEC_WIDTH, SEC_HEIGHT, SEC_FRAME);
}

