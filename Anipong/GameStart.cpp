#include "GameStart.h"
#include <Windows.h>
#include "Common.h"
#include "Bitmap.h"

GameStart::GameStart(): BitMap(START_BG_ID)
{
	m_nId = START_BG_ID;		//프레임 bitmap id
	m_nX = FRAME_START_X;
	m_nY = FRAME_START_Y;		
	m_nWidth = FRAME_WIDTH;
	m_nHeight = FRAME_HEIGHT;	//가로/세로
	m_nStatus = 0;
}
GameStart::~GameStart()
{
}

void GameStart::showBG()
{
	showBitmap(FRAME_START_X, FRAME_START_Y, FRAME_WIDTH, FRAME_HEIGHT, START_BG_ID);
}
void GameStart::showStartButton()
{
	showBitmap(SBUTTON_UPLEFT_X, SBUTTON_UPLEFT_Y, FRAME_WIDTH, FRAME_HEIGHT, START_BUTTON);
}

//void GameStart::Bshow(int nX, int nY)
//{
//	hWnd = GetConsoleWindow();
//	hDC = GetDC(hWnd);
//	hInstance = GetModuleHandle(NULL);
//
//	IconBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP23));
//	hMemDC = CreateCompatibleDC(hDC);
//	SelectObject(hMemDC, IconBmp);
//
//	BitBlt(hDC, nX, nY, FRAME_WIDTH, FRAME_HEIGHT, hMemDC, 0, 0, SRCCOPY);
//}
int GameStart::getX()
{
	return FRAME_START_X/BITPERPIX;
}
int GameStart::getY()
{
	return FRAME_START_Y/BITPERPIX;
}
int GameStart::getWidth()
{
	return SBUTTON_WIDTH/BITPERPIX;
}
int GameStart::getHeight()
{
	return SBUTTON_HEIGHT/BITPERPIX;
}
