#include "GameFrame.h"
#include <Windows.h>
#include "Common.h"

GameFrame::GameFrame() : BitMap(GAME_FRAME_ID)
{
	m_nId = GAME_FRAME_ID;		//������ bitmap id
	m_nX = FRAME_START_X;
	m_nY = FRAME_START_Y;
	m_nWidth = FRAME_WIDTH;
	m_nHeight = FRAME_HEIGHT;	//����/����
	m_nStatus = 0;
}
GameFrame::~GameFrame()
{

}

void GameFrame::showFrame()
{
	showBitmap(FRAME_START_X, FRAME_START_Y, FRAME_WIDTH, FRAME_HEIGHT,GAME_FRAME_ID);
}
void GameFrame::getCoord()
{

}
void GameFrame::setCoord()
{

}
void GameFrame::getSize(int width)
{

}
void GameFrame::setSize(int height)
{

}
void GameFrame::getTime()
{

}
void GameFrame::setTime()
{

}

//void GameFrame::SetCursorShow(int nV)
//{
//	CONSOLE_CURSOR_INFO ConsoleCursor;
//	ConsoleCursor.bVisible = nV;	// true ����, false �Ⱥ���
//	ConsoleCursor.dwSize = 1;			// Ŀ��������
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
//}