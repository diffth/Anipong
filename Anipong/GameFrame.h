#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "resource.h"
#include "Common.h"
#include "Bitmap.h"

using namespace std;

class GameFrame : public BitMap
{
private:
	int m_nId;					//������
	int m_nX, m_nY;				//��ǥ
	int m_nWidth, m_nHeight;	//����/����
	unsigned int m_nStatus;		//���� ����

public:
	GameFrame();
	~GameFrame();

	void showFrame();
	void getCoord();
	void setCoord();
	void getSize(int nWidth);
	void setSize(int nHeight);
	void getTime();
	void setTime();

//	void SetCursorShow(int nV);
	
};

