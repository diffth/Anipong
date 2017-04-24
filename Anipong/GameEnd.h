#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "resource.h"
#include "Bitmap.h"
using namespace std;



class GameEnd : public BitMap
{
private:
	int m_nId;					//������ id
	int m_nX, m_nY;				//��ǥ
	int m_nWidth, m_nHeight;	//����/����
	unsigned int m_nStatus;		//���� ����

public:
	GameEnd();
	~GameEnd();

	void showBG();
	void showRestartButton();
	void showEndButton();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
};
