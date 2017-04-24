#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "resource.h"
#include "Bitmap.h"
using namespace std;



class GameStart : public BitMap
{
private:
	int m_nId;					//������ id
	int m_nX, m_nY;				//��ǥ
	int m_nWidth, m_nHeight;	//����/����
	unsigned int m_nStatus;		//���� ����

public:
	GameStart();
	~GameStart();

	void showBG();//show a Bitmap image
	void showStartButton();//show the start button
	int getX();
	int getY();
	int getWidth();
	int getHeight();
};
