#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;


class Mouse 
{
private:
	int m_nX;
	int m_nY;
	HANDLE COUT;    // 콘솔 출력 장치
	HANDLE CIN;        // 콘솔 입력 장치

public:
	Mouse();
	~Mouse(){}
	int ctrlMouse(); //마우스함수들을 호출하는 마우스의 매인함수
	bool beInput();	// 마우스 이벤트가 있으면 True 아니면 false				
	int getMousePos(WORD *vkey, COORD *pos); //콘솔의 마우스 좌표 받아오는 함수

	int getX();
	int getY();
//	void initMouse();
};

