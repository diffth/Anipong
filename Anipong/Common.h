#pragma once

#define FRAME_START_X		180		//프레임 시작 X
#define FRAME_START_Y		37		//프레임 시작 Y
#define FRAME_WIDTH			252		//프레임가로
#define FRAME_HEIGHT		341		//프레임세로
#define SBUTTON_X_OFFSET	74
#define SBUTTON_Y_OFFSET	250
#define SBUTTON_UPLEFT_X	(FRAME_START_X+SBUTTON_X_OFFSET)	//시작버튼 좌상 X
#define SBUTTON_UPLEFT_Y	(FRAME_START_Y+SBUTTON_Y_OFFSET)	//시작버튼 좌상 Y

//#define RBUTTON_X_OFFSET	(SBUTTON_UPLEFT_X - SBUTTON_X_OFFSET/2)
//#define RBUTTON_Y_OFFSET	FRAME_START_Y + 230
//#define EBUTTON_X_OFFSET	FRAME_START_X + 300
//#define EBUTTON_Y_OFFSET	FRAME_START_Y + 230

#define RBUTTON_UPLEFT_X	(SBUTTON_UPLEFT_X - SBUTTON_X_OFFSET/2)
#define RBUTTON_UPLEFT_Y	SBUTTON_UPLEFT_Y - 5
#define EBUTTON_UPLEFT_X	(SBUTTON_UPLEFT_X + SBUTTON_X_OFFSET/2)
#define EBUTTON_UPLEFT_Y	RBUTTON_UPLEFT_Y - 5



#define SBUTTON_WIDTH		104		//시작버튼 가로 픽셀
#define SBUTTON_HEIGHT		36		//시작버튼 세로 픽셀
#define SCOREBD_X			33   // cusor좌표
#define SCOREBD_Y			3

#define END_SCORE_X			(SCOREBD_X + 4)
#define END_SCORE_Y			(SCOREBD_Y + 6)

#define BITPERPIX			12		//

#define SEC_START_X			FRAME_START_X + 26		//TIME SEC 시작 X
#define SEC_START_Y			FRAME_START_Y + 42		//TIME SEC 시작 Y
#define SEC_WIDTH			3		//TIME SEC 가로
#define SEC_HEIGHT			10		//TIME SEC 세로

#define ICON_ROW			7	// 아이콘 배열 가로줄
#define ICON_COL			7   // 아이콘 배열 세로줄

#define TIMER_COL			60 // timer 칸 수

#define ICON_TOTAL			18	// 전체 아이콘 갯수 (베이직 8 + active 8 + pong 1 + empty 1)
#define ICON_WIDTH			36	// 아이콘 하나 가로 길이
#define ICON_HEIGHT			36	// 아이콘 하나 세로 길이
#define BITPERPIX			12	// Pixel당 비트 크기

#define ICON_UPLEFT_X		FRAME_START_X
#define ICON_UPLEFT_Y		(FRAME_START_Y + 60)


#define PONG_ID				(IDB_BITMAP17 - 101) // Pong 아이콘
#define EMPTY_ID			(IDB_BITMAP18 - 101) // Pong 직후 지워진모습
#define START_BG_ID			(IDB_BITMAP19 - 101) // 게임 시작이미지
#define END_BG_ID			(IDB_BITMAP20 - 101) // 게임 시작이미지
#define GAME_FRAME_ID		(IDB_BITMAP24 - 101) // 게임 프레임 이미지
#define START_BUTTON		(IDB_BITMAP23 - 101) //Start button
#define END_BUTTON			(IDB_BITMAP21 - 101)
#define RESTART_BUTTON		(IDB_BITMAP22 - 101)
#define SEC_FRAME			(IDB_BITMAP25 - 101)
#define SEC_EMPTY			(IDB_BITMAP26 - 101)

//#define IDB_BITMAP17 // Pong 아이콘
//#define IDB_BITMAP18 // empty 아이콘
//#define IDB_BITMAP19 // 게임시작화면
//#define IDB_BITMAP20 // 게임종료화면
//#define IDB_BITMAP21 // 그만하기
//#define IDB_BITMAP22 // 재시작버튼
//#define IDB_BITMAP23 // 게임시작버튼
//#define IDB_BITMAP24 // 게임프레임
