
#include <Windows.h>
#include "Bitmap.h"
#include "Common.h"
#include "resource.h"

BitMap::BitMap(int nBitmapId)
{
	m_nBitmapId = nBitmapId;

	m_hWnd = GetConsoleWindow();
	m_hDC = GetDC(m_hWnd);
	m_hInstance = GetModuleHandle(NULL);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_ImageBmp = 0;
}

void BitMap::showBitmap(int nX, int nY, int nWidth, int nHeight, int nBitmapId)
{
	m_ImageBmp = LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP1 + nBitmapId));
	SelectObject(m_hMemDC, m_ImageBmp);

	BitBlt(m_hDC, nX, nY, nWidth, nHeight, m_hMemDC, 0, 0, SRCCOPY);
}
