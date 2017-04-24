#include <iostream>
#include <process.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Icon.h" //Icon class
#include "Timer.h"
#include "RefreshScreen.h"
#include "Anipong.h"
#include "Common.h"
#include "Mouse.h"
#include "GameStart.h"
#include "GameFrame.h"
#include "GameEnd.h"

using namespace std;

extern Icon iconArr[7][7];// ���� ������ �迭
extern Timer tsArr[TIMER_COL];

extern HANDLE hTimeOutEvent;

void SetCursorShow(int nV);

extern unsigned int CALLBACK ThreadTimer(void* arg);//timerthread Thread
extern unsigned int CALLBACK ThreadRefreshScreen(void* arg);//screen refrash Thread

	
void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


///////////// TODO : ����ȭ�� �ʱ�ȭ
// Ÿ�̸� ���� 

// ������ �ڼ��� - ���� ���� ������ 

/////////////// TODO : ���ӽ���
// ������ �����ֱ�
// Ÿ�̸� ���� : 60��, Ÿ�̸� ������ ����, 1�ʿ� �ѹ� ���ҵǴ� ī����
// 
// ���콺 �Է� ��� 
// ���콺 �Է� ������
// ���õ� ������ Ȱ��ȭ : Active icon���� id �����ϰ� show icon
// �ι�° ���콺 �Է� ������
//		���õ� ������ Ȱ��ȭ : Active icon���� id �����ϰ� show icon
//		������ Swap
//		check Bingo : ���� �ִ��� Ȯ��
//		���� ������ Pong ����
//			: ���� �ش��ϴ� ������ pong���� ����
//			: ������ redraw
//			: empty�� ����
//			: ������ redraw
//		refill icon ���� 
//			: �Ʒ� ������ �� ������ ����߸��� ���� ���� Random icon���� ä���)
//			
//		���� ������ �ٽ� ������ Swap 
//			������ id basic���� ����
//
//	���� ���콺 �Է� ��ٸ�
//
// �ð��� ����Ǹ� ���� ȭ������ �̵�
// ���� �����ְ�
// restart : ���� �����
// ������ : ���� ���� 


void main()
{
	//Thread ���� �� �͵�
	//	srand((unsigned int)time(NULL));
	//	HANDLE hThread[2];
	//	char* str[] = { "Timer Thread", "Refresh screen" };
    //	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadTimer, (void*)str[0], 0, NULL);
	//hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadRefreshScreen, (void*)str[1], 0, NULL);
		// 

	///////////////// ���� �ʱ�ȭ ///////////////////////////
	HANDLE hThread[2];
	Anipong ap;			//Anipong main control Ŭ���� ��ü ����
	GameStart gs;		//���ӽ��� ȭ�� ��ü����
	GameFrame gf;		//���������� Ŭ���� ��ü ����
	GameEnd ge;
	Mouse ms;			//���콺 ��ü ����
	Timer tm;
	
	char* str[] = { "Timer Thread", "Refresh screen" };

	hTimeOutEvent = CreateEvent(NULL, TRUE, FALSE, NULL); //timeout check
	//hRefreshWindowEvent 
	if (hTimeOutEvent == NULL) return;
	

	SetCursorShow(0);	//ȭ�� Ŀ�� ��Ȱ��ȭ
	
	gs.showBG();		//���ӽ��� ȭ��

	
/////////////// TODO : ���ӽ����� ������ ����ȭ������ �̵�
// ���콺 �Է� ��� TODO
//
	while(1)
	{
		ms.ctrlMouse(); //���콺 ���� Ŭ�� �� �ȼ��� ��ǥ�� ����
		if(ms.getX()>= SBUTTON_UPLEFT_X && ms.getX()<= SBUTTON_UPLEFT_X+SBUTTON_WIDTH &&
			ms.getY()>= SBUTTON_UPLEFT_Y && ms.getY()<= SBUTTON_UPLEFT_Y+SBUTTON_HEIGHT)
			break;
	}
/////////////////// Game Frame display ///////////////	
	gf.showFrame();

/////////////////// Timer set and Display ////////////
	ap.setCoordTimers();
	ap.displayTimers();


	/////////////// TODO : ����ȭ�� �ʱ�ȭ ///////////////////////

	// Ÿ�̸� ���� 


	// ��ǥ �ʱ�ȭ
	ap.setCoordIcons();


	/////////////// TODO : ���ӽ���
	// ������ �����ֱ�
	// ������ �ڼ��� - ���� ���� ������ 
	do
	{
		ap.resetBingo();
		ap.makeRandomIcons();
		Sleep(1);
	} while (ap.checkBingo());

	// ������ Display
	ap.displayIcons();

//	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadRefreshScreen, (void*)str[1], 0, NULL);

// Ÿ�̸� ���� : 60��, Ÿ�̸� ������ ����, 1�ʿ� �ѹ� ���ҵǴ� ī����
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadTimer, (void*)str[0], 0, NULL);

	while(1)
	{
		DWORD dwEvent =	WaitForSingleObject(hTimeOutEvent, 10);
		if (dwEvent == WAIT_OBJECT_0)
		{
			ge.showBG();
			//ge.showRestartButton();
			//ge.showEndButton();
			gotoxy(END_SCORE_X, END_SCORE_Y);
			cout << ap.getScore() << endl;
		//	break;
		}

		int row1 = 0;
		int col1 = 0;
		int row2 = 0;
		int col2 = 0;
		//gotoxy(0, 0);
		for(int i=0;i<2;i++)
		{
			ms.ctrlMouse(); //���콺 ���� Ŭ�� �� �ȼ��� ��ǥ�� ����
			//�����ܵ��� �ִ°��� Ŭ�� �� �ÿ��� �����ϵ���

			if(i==0)
			{
				if((ms.getX()>= FRAME_START_X && ms.getX()<= (FRAME_WIDTH + FRAME_START_X)) && //X������ ũ�� �� X���� +  X������ ũ�� 
					(ms.getY()>= (FRAME_START_Y+60)  && ms.getY()<= (FRAME_HEIGHT-3)))//Y������ ũ�� + 60 �� Y���� -  3 
				{
				//	cout<<"X = "<<ms.getX()<<"	Y = "<<ms.getY()<<endl;
					col1= (ms.getX()/ ICON_WIDTH)-5;
					row1= (ms.getY()/ ICON_HEIGHT)-3;
					 
				//	cout<<col1<<"	"<<row1+1<<endl;
					ap.setActive(row1, col1); // Active icon���� id �����ϰ� show icon
				}
			}

			else if(i==1)
			{
				//cout<<"X = "<<ms.getX()<<"	Y = "<<ms.getY()<<endl;
				col2 = ms.getX() / ICON_WIDTH - 5;
				row2 = ms.getY() / ICON_HEIGHT - 3;
				if((row2 == row1+1 || row2 == row1-1 || row2 == row1) &&
					(col2 == col1+1 || col2 == col1-1 || col2 == col1))
				{
					ap.setActive(row2, col2);
					break;
				}
				else //for �� �ٽõ���
				{
					ap.resetActive(row1, col1); // �ٽ� basic ���������� 
					row1 = 0; // �ٽ� ���⶧���� �ʱ�ȭ
					col1 = 0;
					row2 = 0;
					col2 = 0;
					i=-1; //for �� �ٽ� �������� 0���� �ʱ�ȭ ������ ���� ������ -1
				}
			}
		}
		ap.swapIcons(row1, col1, row2, col2); // Swap

		ap.resetActive(row1, col1); // �ٽ� basic ���������� 
		ap.resetActive(row2, col2);
		
		if (ap.checkBingo())//���� ������
		{
			while (ap.checkBingo())//���� ���������� ��� ����
			{
				//pong
				ap.pongBingo();
				ap.setDownIcons();
				ap.refillIcons();
			}
		}
		else //���� ������
		{
			Sleep(500);
			ap.swapIcons(row1, col1, row2, col2); // �ٽ� ������� Swap
		}

	}
// �ι�° ���콺 �Է� ������
//	���õ� ������ Ȱ��ȭ : Active icon���� id �����ϰ� show icon


//		������ Swap


//		check Bingo : ���� �ִ��� Ȯ��
//		���� ������ Pong ����
//			: ���� �ش��ϴ� ������ pong���� ����
//			: ������ redraw
//			: empty�� ����
//			: ������ redraw
//		refill icon ���� 
//			: �Ʒ� ������ �� ������ ����߸��� ���� ���� Random icon���� ä���)
//			
//		���� ������ �ٽ� ������ Swap 
//			������ id basic���� ����
//
//	���� ���콺 �Է� ��ٸ�
//
// �ð��� ����Ǹ� ���� ȭ������ �̵�
// ���� �����ְ�
// restart : ���� �����
// ������ : ���� ���� 

	
//Thread ���� ���ξ����尡 �ٸ� ��������� �� ���������� ��ٸ����� �� , ���� �Լ� ������ ���� �����
// �� �Լ� ���� �ڵ���� ������� ����.
	//WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

	CloseHandle(hTimeOutEvent);

}

void SetCursorShow(int nV)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = nV;	// true ����, false �Ⱥ���
	ConsoleCursor.dwSize = 1;			// Ŀ��������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
}