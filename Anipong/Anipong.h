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
	//Icon** pIcon;//Ŭ���� ���� 2�� ��� �����ؼ� ����ϴ� ���
public:
	Anipong()
	{
		m_nScore = 0;
		m_hWnd = GetConsoleWindow();
		srand((unsigned int)time(NULL));
	}
		~Anipong() {};
/* Ŭ���� ���� 2�� ��� �����ؼ� ����ϴ� ���
	Anipong() 
	{ 
		m_nScore = 0;
		pIcon = new Icon*[7]();//Row ���� �� �޸� �Ҵ�
		for (int i = 0; i < 7; i++)
			pIcon[i] = new Icon[7];//Col ���� �� �޸� �Ҵ�
		pIcon[0][0].m_nId = 77;
	}
	~Anipong()
	{
		for (int i = 0; i < 7; i++) //Row ���� Col �޸�����
			delete[] *(pIcon+i);
		delete[] pIcon;// row �޸� ����
	}

*/
public:
	void setCoordIcons();
	void displayIcons();
	void displayTimers();
	void makeRandomIcons();//random ������ ���̵� �����ؼ� �迭�� ����
	void setCoordTimers();
	void redrawIcons();//������ �迭�� ���̵� �°� ȭ�� �׸���
	void setScore(int nScore) { m_nScore += nScore; } //������ ++
	int getScore(); //������ ����
	int checkBingo();//�� �������� �˻��Ͽ� ��Ʈ������ ã�Ƴ�,����ġ�Ұ��ΰ�,�ٽ� �������ΰ� �Ǵ��� ��� ����
	void resetBingo();//���� �÷��� �ʱ�ȭ
	void setActive(int nRow, int nCol); //���콺 Ŭ�������� active ���������� ����
	void resetActive(int nRow, int nCol); //���콺 Ŭ�������� active ���������� ����
	void swapIcons(int nRow1, int nCol1, int nRow2, int nCol2); //  �� ������ swap
	void setDownIcons();//��������� �Ʒ� �迭�� ��������� �����ܵ� �Ʒ��� �̵�
	void pongBingo();//�����ΰ�� �ش� �����ܵ� pong!!! �ϰ� ����
	int checkBelowEmpty();//�Ʒ�ĭ�� ����ִ� ������ üũ ���� ����
	void refillIcons();// ������� icon �ٽ� ä���
};

