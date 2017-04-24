
#include <ctime>

#include "Anipong.h"
#include "Common.h"


#define __DEBUG__

extern void gotoxy(int x, int y);

extern Icon iconArr[ICON_ROW][ICON_COL];
extern Timer tsArr[TIMER_COL];

class ScoreBd
{
private:
	int m_nScore;
public:
	void setScore(int nScore) { m_nScore = nScore; }
	int getScore() { return m_nScore; }
};

//�����ܸ��� ��ǥ���� ����
void Anipong::setCoordIcons()
{
	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			iconArr[row][col].setCoord(ICON_UPLEFT_X+ ICON_WIDTH*col,
									   ICON_UPLEFT_Y+ ICON_HEIGHT*row);
		}
	}
}

//random ������ ���̵� �����ؼ� �迭�� ����
void Anipong::makeRandomIcons()
{
	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			// ¦�� ID�� �������� �⺻ �������̹Ƿ� 0~15 ���̿� ¦���� random �߻����� ����
			iconArr[row][col].setId(2 * (rand() % 7));
		}
	}
}

void Anipong::displayIcons()
{
	int xOffset = 0;
	int yOffset = 0;
	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		yOffset += ICON_WIDTH;
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			xOffset += ICON_WIDTH;
			iconArr[row][col].showIcon();
		}
		xOffset = 0;
	}
}

void Anipong::displayTimers()
{
	for (int col = 0; col < TIMER_COL; col++)
	{
		tsArr[col].setId(SEC_FRAME);
		tsArr[col].showTimerSec();
	}
}

void Anipong::setCoordTimers()
{
	for (int row = 0; row < TIMER_COL; row++)
	{
		tsArr[row].setCoord(SEC_START_X + (row * 3), SEC_START_Y);
	}
}



//������ ����Ͽ�  ����
//void Anipong::setScore(int nScore)
//{
//	
//}
//������ ++
int Anipong::getScore() { return m_nScore; } //������ ����


int Anipong::checkBingo() 	// �� �˻��ؼ� 3�� �̻� ���ӵǸ� m_isBingo �� true ����
{
	int nNumBingo=0;//���� �� ������ ����

	// 7�� row �˻�
	for (int nRow = 0; nRow < ICON_ROW; nRow++)
	{
		for (int i = 0; i < 5; i++)//�տ������� 3���� 5�� ��
		{
			if (iconArr[nRow][i].getId() == iconArr[nRow][i + 1].getId() &&
				iconArr[nRow][i + 1].getId() == iconArr[nRow][i + 2].getId())//���� 3���� ������
			{
				for (int nBingo = i; nBingo <= i + 2; nBingo++)//���� �ε����� ���� ���� �������� isBingo �� set
					iconArr[nRow][nBingo].setBingo(true); // ���� �� ������
			}
		}
	}
	//7�� col�˻�
	for (int nCol = 0; nCol < ICON_COL; nCol++)// 7�� row �˻�
	{
		for (int i = 0; i < 5; i++)//�տ������� 3���� 5�� ��
		{
			if (iconArr[i][nCol].getId() == iconArr[i + 1][nCol].getId() &&
				iconArr[i + 1][nCol].getId() == iconArr[i + 2][nCol].getId())//���� 3���� ������
			{
				for (int nBingo = i; nBingo <= i+2; nBingo++)//���� �ε����� ���� ���� �������� isBingo �� set
					iconArr[nBingo][nCol].setBingo(true); // ���� �� ������ set
			}
		}
	}

	// ���� ���� �˻�
	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			if (iconArr[row][col].getBingo() == 1)//���� ������ ���� count
				nNumBingo++;
		}
	}
	return nNumBingo;
}

void Anipong::resetBingo()
{
	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			iconArr[row][col].setBingo(false);//���� �÷��� ����
		}
	}
}

void Anipong::setActive(int nRow, int nCol)
{
	iconArr[nRow][nCol].setId(iconArr[nRow][nCol].getId()+1);
	iconArr[nRow][nCol].showIcon();
}

void Anipong::resetActive(int nRow, int nCol)
{
	iconArr[nRow][nCol].setId(iconArr[nRow][nCol].getId()-1);
	iconArr[nRow][nCol].showIcon();
}
void Anipong::swapIcons(int nRow1, int nCol1, int nRow2, int nCol2)
{
	int tempId;
	tempId = iconArr[nRow1][nCol1].getId();
	iconArr[nRow1][nCol1].setId(iconArr[nRow2][nCol2].getId());
	iconArr[nRow2][nCol2].setId(tempId);

	iconArr[nRow1][nCol1].showIcon();
	iconArr[nRow2][nCol2].showIcon();
}

void Anipong::pongBingo() //�����ΰ�� �ش� �����ܵ� clear
{
	//���� ������ �̹��� pong���� ���� // 
	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			if (iconArr[row][col].getBingo())//���� ���¸�
			{
				setActive(row, col);
				iconArr[row][col].showIcon();//Active ������ ���� ����
			}
		}
	}

	Sleep(200);// ��� Active ���·� ���

	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			if (iconArr[row][col].getBingo())//���� ���¸�
			{
				iconArr[row][col].setId(PONG_ID);
				iconArr[row][col].showIcon();
				//���� ������Ŵ
				setScore(100);
				gotoxy(SCOREBD_X, SCOREBD_Y);
				cout << getScore() << endl;
			}
		}
	}

	// ���� �����
	Sleep(200);// ��� Pong ������ ������

	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			if (iconArr[row][col].getBingo())//���� ���¸�
			{
				iconArr[row][col].setId(EMPTY_ID);
				iconArr[row][col].showIcon();
			}
		}
	}
	//Pong �ϰ� ����  isBingo ����
	resetBingo();
}

int Anipong::checkBelowEmpty() // �� �Ұ� �ִ��� Ȯ���ϴ� ���� �ʿ�
{
	int nNumBelowEmpty = 0;
	for (int row = 0; row < ICON_ROW-1; row++)//row ���� 6��° row������
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			if (iconArr[row][col].getId() != EMPTY_ID)
			{
				if (iconArr[row + 1][col].getId() == EMPTY_ID)
				{
					iconArr[row][col].setBelowEmpty(true);
					nNumBelowEmpty++;
				}
			}
			else// ���� �������� emptyID ��
			{
				iconArr[row][col].setBelowEmpty(false);
			}
		}
	}
	return nNumBelowEmpty;
}

void Anipong::setDownIcons()
{
	while (checkBelowEmpty())
	{
		for (int row = 0; row < ICON_ROW; row++)//row ����
		{
			for (int col = 0; col < ICON_COL; col++)// column ����
			{
				if ((row + 1) != ICON_ROW && iconArr[row + 1][col].getId() == EMPTY_ID)
				{
					swapIcons(row, col, row + 1, col);// �Ʒ��� ��ĭ�̵�
					//Sleep(50);
				}
			}
		}
	}
}

void Anipong::refillIcons() //�� ������ ä���
{
	for (int row = 0; row < ICON_ROW; row++)//row ����
	{
		for (int col = 0; col < ICON_COL; col++)// column ����
		{
			if (iconArr[row][col].getId() == EMPTY_ID)
			{
				iconArr[row][col].setId(2 * (rand() % 7));
				iconArr[row][col].showIcon();
			}
		}
	}
}



