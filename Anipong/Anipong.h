#pragma once

#include <iostream>
#include "Timer.h"
#include "Icon.h"
#include "Common.h"
#include <time.h>

using namespace std;

// Anipong Class
class Anipong
{
private:
	int m_nScore;
	HWND	m_hWnd;
//	HDC		m_hDC;
//	HINSTANCE	m_hInstance;
//	HDC		m_hMemDC;
	//Icon** pIcon;//클래스 내에 2중 어래이 선언해서 사용하는 경우
public:
	Anipong()
	{
		m_nScore = 0;
		m_hWnd = GetConsoleWindow();
		srand((unsigned int)time(NULL));
	}
		~Anipong() {};
/* 클래스 내에 2중 어래이 선언해서 사용하는 경우
	Anipong() 
	{ 
		m_nScore = 0;
		pIcon = new Icon*[7]();//Row 생성 및 메모리 할당
		for (int i = 0; i < 7; i++)
			pIcon[i] = new Icon[7];//Col 생성 및 메모리 할당
		pIcon[0][0].m_nId = 77;
	}
	~Anipong()
	{
		for (int i = 0; i < 7; i++) //Row 별로 Col 메모리해제
			delete[] *(pIcon+i);
		delete[] pIcon;// row 메모리 해제
	}

*/
public:
	void setCoordIcons();
	void displayIcons();
	void displayTimers();
	void makeRandomIcons();//random 아이콘 아이디 생성해서 배열에 저장
	void setCoordTimers();
	void redrawIcons();//아이콘 배열의 아이디에 맞게 화면 그리기
	void setScore(int nScore) { m_nScore += nScore; } //점수를 ++
	int getScore(); //점수를 얻어옴
	int checkBingo();//각 아이콘을 검사하여 터트릴것을 찾아냄,원위치할것인가,다시 섞을것인가 판단후 결과 리턴
	void resetBingo();//빙고 플래그 초기화
	void setActive(int nRow, int nCol); //마우스 클릭받으면 active 아이콘으로 변경
	void resetActive(int nRow, int nCol); //마우스 클릭받으면 active 아이콘으로 변경
	void swapIcons(int nRow1, int nCol1, int nRow2, int nCol2); //  두 아이콘 swap
	void setDownIcons();//현재아이콘 아래 배열이 비어있을때 아이콘들 아래로 이동
	void pongBingo();//빙고인경우 해당 아이콘들 pong!!! 하고 점수
	int checkBelowEmpty();//아래칸이 비어있는 아이콘 체크 갯수 리턴
	void refillIcons();// 빈공간에 icon 다시 채우기
};

