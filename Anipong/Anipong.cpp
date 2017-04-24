
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

//아이콘마다 좌표정보 세팅
void Anipong::setCoordIcons()
{
	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			iconArr[row][col].setCoord(ICON_UPLEFT_X+ ICON_WIDTH*col,
									   ICON_UPLEFT_Y+ ICON_HEIGHT*row);
		}
	}
}

//random 아이콘 아이디 생성해서 배열에 저장
void Anipong::makeRandomIcons()
{
	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			// 짝수 ID의 아이콘이 기본 아이콘이므로 0~15 사이에 짝수를 random 발생시켜 저장
			iconArr[row][col].setId(2 * (rand() % 7));
		}
	}
}

void Anipong::displayIcons()
{
	int xOffset = 0;
	int yOffset = 0;
	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		yOffset += ICON_WIDTH;
		for (int col = 0; col < ICON_COL; col++)// column 증가
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



//점수를 계산하여  리턴
//void Anipong::setScore(int nScore)
//{
//	
//}
//점수를 ++
int Anipong::getScore() { return m_nScore; } //점수를 얻어옴


int Anipong::checkBingo() 	// 을 검사해서 3개 이상 연속되면 m_isBingo 에 true 저장
{
	int nNumBingo=0;//빙고가 된 아이콘 갯수

	// 7개 row 검사
	for (int nRow = 0; nRow < ICON_ROW; nRow++)
	{
		for (int i = 0; i < 5; i++)//앞에서부터 3개식 5번 비교
		{
			if (iconArr[nRow][i].getId() == iconArr[nRow][i + 1].getId() &&
				iconArr[nRow][i + 1].getId() == iconArr[nRow][i + 2].getId())//연속 3개가 같으면
			{
				for (int nBingo = i; nBingo <= i + 2; nBingo++)//현재 인덱스로 부터 세개 아이콘의 isBingo 를 set
					iconArr[nRow][nBingo].setBingo(true); // 빙고가 된 아이콘
			}
		}
	}
	//7개 col검사
	for (int nCol = 0; nCol < ICON_COL; nCol++)// 7개 row 검사
	{
		for (int i = 0; i < 5; i++)//앞에서부터 3개식 5번 비교
		{
			if (iconArr[i][nCol].getId() == iconArr[i + 1][nCol].getId() &&
				iconArr[i + 1][nCol].getId() == iconArr[i + 2][nCol].getId())//연속 3개가 같으면
			{
				for (int nBingo = i; nBingo <= i+2; nBingo++)//현재 인덱스로 부터 세개 아이콘의 isBingo 를 set
					iconArr[nBingo][nCol].setBingo(true); // 빙고가 된 아이콘 set
			}
		}
	}

	// 빙고 갯수 검사
	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			if (iconArr[row][col].getBingo() == 1)//빙고 아이콘 갯수 count
				nNumBingo++;
		}
	}
	return nNumBingo;
}

void Anipong::resetBingo()
{
	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			iconArr[row][col].setBingo(false);//빙고 플래그 리셋
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

void Anipong::pongBingo() //빙고인경우 해당 아이콘들 clear
{
	//빙고 아이콘 이미지 pong으로 변경 // 
	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			if (iconArr[row][col].getBingo())//빙고 상태면
			{
				setActive(row, col);
				iconArr[row][col].showIcon();//Active 아이콘 으로 변경
			}
		}
	}

	Sleep(200);// 잠깐 Active 상태로 대기

	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			if (iconArr[row][col].getBingo())//빙고 상태면
			{
				iconArr[row][col].setId(PONG_ID);
				iconArr[row][col].showIcon();
				//점수 증가시킴
				setScore(100);
				gotoxy(SCOREBD_X, SCOREBD_Y);
				cout << getScore() << endl;
			}
		}
	}

	// 빙고 지우기
	Sleep(200);// 잠깐 Pong 아이콘 보여줌

	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			if (iconArr[row][col].getBingo())//빙고 상태면
			{
				iconArr[row][col].setId(EMPTY_ID);
				iconArr[row][col].showIcon();
			}
		}
	}
	//Pong 하고 나면  isBingo 리셋
	resetBingo();
}

int Anipong::checkBelowEmpty() // 더 할게 있는지 확인하는 과정 필요
{
	int nNumBelowEmpty = 0;
	for (int row = 0; row < ICON_ROW-1; row++)//row 증가 6번째 row까지만
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			if (iconArr[row][col].getId() != EMPTY_ID)
			{
				if (iconArr[row + 1][col].getId() == EMPTY_ID)
				{
					iconArr[row][col].setBelowEmpty(true);
					nNumBelowEmpty++;
				}
			}
			else// 현재 아이콘이 emptyID 면
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
		for (int row = 0; row < ICON_ROW; row++)//row 증가
		{
			for (int col = 0; col < ICON_COL; col++)// column 증가
			{
				if ((row + 1) != ICON_ROW && iconArr[row + 1][col].getId() == EMPTY_ID)
				{
					swapIcons(row, col, row + 1, col);// 아래로 한칸이동
					//Sleep(50);
				}
			}
		}
	}
}

void Anipong::refillIcons() //빈 아이콘 채우기
{
	for (int row = 0; row < ICON_ROW; row++)//row 증가
	{
		for (int col = 0; col < ICON_COL; col++)// column 증가
		{
			if (iconArr[row][col].getId() == EMPTY_ID)
			{
				iconArr[row][col].setId(2 * (rand() % 7));
				iconArr[row][col].showIcon();
			}
		}
	}
}



