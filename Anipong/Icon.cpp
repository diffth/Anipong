#include "Icon.h"
#include <Windows.h>
#include "Common.h"

Icon iconArr[7][7];

Icon::Icon() : BitMap(EMPTY_ID)
{
	m_nId = EMPTY_ID;		//프레임 bitmap id
	m_nX = ICON_UPLEFT_X;
	m_nY = ICON_UPLEFT_Y;
	m_nWidth = ICON_WIDTH;
	m_nHeight = ICON_HEIGHT;	//가로/세로
	m_nStatus = 0;
	m_isBelowEmpty = false; //초기값
}
Icon::~Icon()
{
}

void Icon::showIcon()
{
	showBitmap(m_nX, m_nY, ICON_WIDTH, ICON_HEIGHT, m_nId);
}
