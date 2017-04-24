#include <iostream> 
#include <Windows.h>
#include "Mouse.h"

using namespace std;

Mouse::Mouse()
{
	DWORD mode;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(CIN,&mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
}
bool Mouse::beInput() // 마우스 이벤트가 있으면 True 아니면 false
{
	INPUT_RECORD input_record;
	DWORD isBeinput=0;

	PeekConsoleInput(CIN, &input_record, 1, &isBeinput);
	return isBeinput;
}

int Mouse::getMousePos(WORD *vkey, COORD *pos)
{
	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch(input_record.EventType) {
	case MOUSE_EVENT:
		if((input_record.Event.MouseEvent.dwEventFlags == MOUSE_MOVED))
			return FALSE; // 마우스 드래그 방지

		if(pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
			return MOUSE_EVENT;

		break;

	}

	FlushConsoleInputBuffer(CIN);
	return 0;
}

int Mouse::ctrlMouse() //마우스함수들을 호출하는 마우스의 매인함수
{

	WORD key;
	COORD pos;

	while(1)
	{
		if(beInput()) 
		{    
			if(getMousePos(&key,&pos) != 0 ) //입력이 왼쪽 클릭일 시 MOUSE_EVENT reteurn         
			{
				int width = 0;
				POINT a;
				HWND hWnd;
				RECT window_size;
				a.x = 0;
				a.y = 0;

				GetCursorPos(&a); //return 했을때의 위치를 저장함
				hWnd = WindowFromPoint(a);
				ScreenToClient(hWnd, &a);
				GetWindowRect(hWnd, &window_size);
				width = (window_size.right - window_size.left);
				m_nX = a.x;
				m_nY = a.y;
				return 0;
			}
		}
	}
}

int Mouse::getX()
{
	return m_nX;
}

int Mouse::getY()
{
	return m_nY;
}
