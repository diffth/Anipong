#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "resource.h"
#include "GameFrame.h"
#include "Common.h"
#include "Bitmap.h"

using namespace std;

class Icon : public BitMap
{
private:
	int m_nId;
	int m_nX, m_nY;				//��ǥ
	int m_nWidth, m_nHeight;	//����/����
	unsigned int m_nStatus;		//���� ����
	bool m_isBingo;				//���� ����(true/false)
	bool m_isBelowEmpty;		//�Ʒ� ĭ�� ����ִ��� ����(true/false)

public:
	Icon();					//������
	~Icon();				//�Ҹ���

public:
	void showIcon();//show its Icon
	void setId(int nId) { m_nId = nId; }
	int getId() { return m_nId; }

	void setBingo(bool isBingo) { m_isBingo = isBingo; }
	int getBingo() { return m_isBingo; }
	
	void setCoord(int nX, int nY) { m_nX = nX; m_nY = nY; }
	void getCoord(int* nX, int* nY) { *nX = m_nX; *nY = m_nY; }
	
	void setWidth(int nWidth) { m_nWidth = nWidth; }
	int getWidth() { return m_nWidth; }

	void setHeight(int nHeight) { m_nHeight = nHeight; }
	int getHeight() { return m_nHeight; }

	void setBelowEmpty(bool isBelowEmpty) { m_isBelowEmpty = isBelowEmpty; }
	int getBelowEmpty() { return m_isBelowEmpty; }// �Ʒ�ĭ�� ������� üũ
	
//	void move(string str);	//up down left right // Anipong���� ó��
};

