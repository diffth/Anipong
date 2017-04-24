#pragma once
#include <Windows.h>

//Bit 맵을 사용하기 위한 변수들과 공용  display  함수 제공
class BitMap
{
private:
	int m_nBitmapId;
protected:
	HWND	m_hWnd;
	HDC		m_hDC;
	HINSTANCE	m_hInstance;
	HBITMAP m_ImageBmp;
	HDC		m_hMemDC;

public:
//	BitMap(){};
	BitMap(int nBitmapId);
	~BitMap(){};
public:
	void showBitmap(int nX, int nY, int nWidth, int nHeight, int nBitmapId);
		
};


