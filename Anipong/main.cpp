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

extern Icon iconArr[7][7];// 전역 아이콘 배열
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


///////////// TODO : 게임화면 초기화
// 타이머 리셋 

// 아이콘 뒤섞기 - 빙고가 없을 때까지 

/////////////// TODO : 게임시작
// 아이콘 보여주기
// 타이머 시작 : 60초, 타이머 쓰레드 시작, 1초에 한번 감소되는 카운터
// 
// 마우스 입력 대기 
// 마우스 입력 받으면
// 선택된 아이콘 활성화 : Active icon으로 id 변경하고 show icon
// 두번째 마우스 입력 받으면
//		선택된 아이콘 활성화 : Active icon으로 id 변경하고 show icon
//		아이콘 Swap
//		check Bingo : 빙고가 있는지 확인
//		빙고가 있으면 Pong 실행
//			: 빙고에 해당하는 아이콘 pong으로 변경
//			: 아이콘 redraw
//			: empty로 변경
//			: 아이콘 redraw
//		refill icon 실행 
//			: 아랫 공간이 빈 아이콘 떨어뜨리고 남은 공간 Random icon으로 채우기)
//			
//		빙고가 없으면 다시 아이콘 Swap 
//			아이콘 id basic으로 변경
//
//	다음 마우스 입력 기다림
//
// 시간이 만료되면 종료 화면으로 이동
// 점수 보여주고
// restart : 게임 재시작
// 나가기 : 게임 종료 


void main()
{
	//Thread 사용시 쓸 것들
	//	srand((unsigned int)time(NULL));
	//	HANDLE hThread[2];
	//	char* str[] = { "Timer Thread", "Refresh screen" };
    //	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadTimer, (void*)str[0], 0, NULL);
	//hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadRefreshScreen, (void*)str[1], 0, NULL);
		// 

	///////////////// 게임 초기화 ///////////////////////////
	HANDLE hThread[2];
	Anipong ap;			//Anipong main control 클래스 객체 생성
	GameStart gs;		//게임시작 화면 객체생성
	GameFrame gf;		//게임프레임 클래스 객체 생성
	GameEnd ge;
	Mouse ms;			//마우스 객체 생성
	Timer tm;
	
	char* str[] = { "Timer Thread", "Refresh screen" };

	hTimeOutEvent = CreateEvent(NULL, TRUE, FALSE, NULL); //timeout check
	//hRefreshWindowEvent 
	if (hTimeOutEvent == NULL) return;
	

	SetCursorShow(0);	//화면 커서 비활성화
	
	gs.showBG();		//게임시작 화면

	
/////////////// TODO : 게임시작을 누르면 게임화면으로 이동
// 마우스 입력 대기 TODO
//
	while(1)
	{
		ms.ctrlMouse(); //마우스 왼쪽 클릭 시 픽셀로 좌표를 저장
		if(ms.getX()>= SBUTTON_UPLEFT_X && ms.getX()<= SBUTTON_UPLEFT_X+SBUTTON_WIDTH &&
			ms.getY()>= SBUTTON_UPLEFT_Y && ms.getY()<= SBUTTON_UPLEFT_Y+SBUTTON_HEIGHT)
			break;
	}
/////////////////// Game Frame display ///////////////	
	gf.showFrame();

/////////////////// Timer set and Display ////////////
	ap.setCoordTimers();
	ap.displayTimers();


	/////////////// TODO : 게임화면 초기화 ///////////////////////

	// 타이머 리셋 


	// 좌표 초기화
	ap.setCoordIcons();


	/////////////// TODO : 게임시작
	// 아이콘 보여주기
	// 아이콘 뒤섞기 - 빙고가 없을 때까지 
	do
	{
		ap.resetBingo();
		ap.makeRandomIcons();
		Sleep(1);
	} while (ap.checkBingo());

	// 아이콘 Display
	ap.displayIcons();

//	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadRefreshScreen, (void*)str[1], 0, NULL);

// 타이머 시작 : 60초, 타이머 쓰레드 시작, 1초에 한번 감소되는 카운터
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
			ms.ctrlMouse(); //마우스 왼쪽 클릭 시 픽셀로 좌표를 저장
			//아이콘들이 있는곳을 클릭 할 시에만 실행하도록

			if(i==0)
			{
				if((ms.getX()>= FRAME_START_X && ms.getX()<= (FRAME_WIDTH + FRAME_START_X)) && //X쪽으로 크기 와 X넓이 +  X쪽으로 크기 
					(ms.getY()>= (FRAME_START_Y+60)  && ms.getY()<= (FRAME_HEIGHT-3)))//Y쪽으로 크기 + 60 와 Y넓이 -  3 
				{
				//	cout<<"X = "<<ms.getX()<<"	Y = "<<ms.getY()<<endl;
					col1= (ms.getX()/ ICON_WIDTH)-5;
					row1= (ms.getY()/ ICON_HEIGHT)-3;
					 
				//	cout<<col1<<"	"<<row1+1<<endl;
					ap.setActive(row1, col1); // Active icon으로 id 변경하고 show icon
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
				else //for 문 다시돈다
				{
					ap.resetActive(row1, col1); // 다시 basic 아이콘으로 
					row1 = 0; // 다시 돌기때문에 초기화
					col1 = 0;
					row2 = 0;
					col2 = 0;
					i=-1; //for 문 다시 돌기위해 0으로 초기화 하지만 후위 증가라 -1
				}
			}
		}
		ap.swapIcons(row1, col1, row2, col2); // Swap

		ap.resetActive(row1, col1); // 다시 basic 아이콘으로 
		ap.resetActive(row2, col2);
		
		if (ap.checkBingo())//빙고가 있으면
		{
			while (ap.checkBingo())//빙고가 없을때까지 계속 실행
			{
				//pong
				ap.pongBingo();
				ap.setDownIcons();
				ap.refillIcons();
			}
		}
		else //빙고가 없으면
		{
			Sleep(500);
			ap.swapIcons(row1, col1, row2, col2); // 다시 원래대로 Swap
		}

	}
// 두번째 마우스 입력 받으면
//	선택된 아이콘 활성화 : Active icon으로 id 변경하고 show icon


//		아이콘 Swap


//		check Bingo : 빙고가 있는지 확인
//		빙고가 있으면 Pong 실행
//			: 빙고에 해당하는 아이콘 pong으로 변경
//			: 아이콘 redraw
//			: empty로 변경
//			: 아이콘 redraw
//		refill icon 실행 
//			: 아랫 공간이 빈 아이콘 떨어뜨리고 남은 공간 Random icon으로 채우기)
//			
//		빙고가 없으면 다시 아이콘 Swap 
//			아이콘 id basic으로 변경
//
//	다음 마우스 입력 기다림
//
// 시간이 만료되면 종료 화면으로 이동
// 점수 보여주고
// restart : 게임 재시작
// 나가기 : 게임 종료 

	
//Thread 사용시 메인쓰레드가 다를 쓰레드들이 다 끝날때가지 기다리도록 함 , 메인 함수 끝나기 전에 써야함
// 이 함수 다음 코드들은 실행되지 않음.
	//WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

	CloseHandle(hTimeOutEvent);

}

void SetCursorShow(int nV)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = nV;	// true 보임, false 안보임
	ConsoleCursor.dwSize = 1;			// 커서사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // 설정
}