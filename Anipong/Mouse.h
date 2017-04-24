#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;


class Mouse 
{
private:
	int m_nX;
	int m_nY;
	HANDLE COUT;    // �ܼ� ��� ��ġ
	HANDLE CIN;        // �ܼ� �Է� ��ġ

public:
	Mouse();
	~Mouse(){}
	int ctrlMouse(); //���콺�Լ����� ȣ���ϴ� ���콺�� �����Լ�
	bool beInput();	// ���콺 �̺�Ʈ�� ������ True �ƴϸ� false				
	int getMousePos(WORD *vkey, COORD *pos); //�ܼ��� ���콺 ��ǥ �޾ƿ��� �Լ�

	int getX();
	int getY();
//	void initMouse();
};

