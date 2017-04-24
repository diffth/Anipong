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
	int m_nX, m_nY;				//좌표
	int m_nWidth, m_nHeight;	//가로/세로
	unsigned int m_nStatus;		//현재 상태
	bool m_isBingo;				//빙고 유무(true/false)
	bool m_isBelowEmpty;		//아래 칸이 비어있는지 여부(true/false)

public:
	Icon();					//생성자
	~Icon();				//소멸자

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
	int getBelowEmpty() { return m_isBelowEmpty; }// 아래칸이 비었는지 체크
	
//	void move(string str);	//up down left right // Anipong에서 처리
};

