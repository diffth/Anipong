#pragma once
#include <Windows.h>

//Bit ���� ����ϱ� ���� ������� ����  display  �Լ� ����
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


