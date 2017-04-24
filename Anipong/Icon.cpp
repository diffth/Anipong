#include "Icon.h"
#include <Windows.h>
#include "Common.h"

Icon iconArr[7][7];

Icon::Icon() : BitMap(EMPTY_ID)
{
	m_nId = EMPTY_ID;		//������ bitmap id
	m_nX = ICON_UPLEFT_X;
	m_nY = ICON_UPLEFT_Y;
	m_nWidth = ICON_WIDTH;
	m_nHeight = ICON_HEIGHT;	//����/����
	m_nStatus = 0;
	m_isBelowEmpty = false; //�ʱⰪ
}
Icon::~Icon()
{
}

void Icon::showIcon()
{
	showBitmap(m_nX, m_nY, ICON_WIDTH, ICON_HEIGHT, m_nId);
}
