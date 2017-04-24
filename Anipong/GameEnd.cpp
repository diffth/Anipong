#include "GameEnd.h"
#include <Windows.h>
#include "Common.h"
#include "Bitmap.h"

GameEnd::GameEnd() : BitMap(END_BG_ID)
{
	m_nId = START_BG_ID;		//프레임 bitmap id
	m_nX = FRAME_START_X;
	m_nY = FRAME_START_Y;
	m_nWidth = FRAME_WIDTH;
	m_nHeight = FRAME_HEIGHT;	//가로/세로
	m_nStatus = 0;
}
GameEnd::~GameEnd()
{
}

void GameEnd::showBG()
{
	showBitmap(FRAME_START_X, FRAME_START_Y, FRAME_WIDTH, FRAME_HEIGHT, END_BG_ID);
}
void GameEnd::showRestartButton()
{
	showBitmap(EBUTTON_UPLEFT_X, EBUTTON_UPLEFT_Y, FRAME_WIDTH, FRAME_HEIGHT, RESTART_BUTTON);
}
void GameEnd::showEndButton()
{
	showBitmap(EBUTTON_UPLEFT_X, EBUTTON_UPLEFT_Y, FRAME_WIDTH, FRAME_HEIGHT, END_BUTTON);
}

int GameEnd::getX()
{
	return FRAME_START_X / BITPERPIX;
}
int GameEnd::getY()
{
	return FRAME_START_Y / BITPERPIX;
}
int GameEnd::getWidth()
{
	return SBUTTON_WIDTH / BITPERPIX;
}
int GameEnd::getHeight()
{
	return SBUTTON_HEIGHT / BITPERPIX;
}
