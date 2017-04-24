#pragma once

#define FRAME_START_X		180		//������ ���� X
#define FRAME_START_Y		37		//������ ���� Y
#define FRAME_WIDTH			252		//�����Ӱ���
#define FRAME_HEIGHT		341		//�����Ӽ���
#define SBUTTON_X_OFFSET	74
#define SBUTTON_Y_OFFSET	250
#define SBUTTON_UPLEFT_X	(FRAME_START_X+SBUTTON_X_OFFSET)	//���۹�ư �»� X
#define SBUTTON_UPLEFT_Y	(FRAME_START_Y+SBUTTON_Y_OFFSET)	//���۹�ư �»� Y

//#define RBUTTON_X_OFFSET	(SBUTTON_UPLEFT_X - SBUTTON_X_OFFSET/2)
//#define RBUTTON_Y_OFFSET	FRAME_START_Y + 230
//#define EBUTTON_X_OFFSET	FRAME_START_X + 300
//#define EBUTTON_Y_OFFSET	FRAME_START_Y + 230

#define RBUTTON_UPLEFT_X	(SBUTTON_UPLEFT_X - SBUTTON_X_OFFSET/2)
#define RBUTTON_UPLEFT_Y	SBUTTON_UPLEFT_Y - 5
#define EBUTTON_UPLEFT_X	(SBUTTON_UPLEFT_X + SBUTTON_X_OFFSET/2)
#define EBUTTON_UPLEFT_Y	RBUTTON_UPLEFT_Y - 5



#define SBUTTON_WIDTH		104		//���۹�ư ���� �ȼ�
#define SBUTTON_HEIGHT		36		//���۹�ư ���� �ȼ�
#define SCOREBD_X			33   // cusor��ǥ
#define SCOREBD_Y			3

#define END_SCORE_X			(SCOREBD_X + 4)
#define END_SCORE_Y			(SCOREBD_Y + 6)

#define BITPERPIX			12		//

#define SEC_START_X			FRAME_START_X + 26		//TIME SEC ���� X
#define SEC_START_Y			FRAME_START_Y + 42		//TIME SEC ���� Y
#define SEC_WIDTH			3		//TIME SEC ����
#define SEC_HEIGHT			10		//TIME SEC ����

#define ICON_ROW			7	// ������ �迭 ������
#define ICON_COL			7   // ������ �迭 ������

#define TIMER_COL			60 // timer ĭ ��

#define ICON_TOTAL			18	// ��ü ������ ���� (������ 8 + active 8 + pong 1 + empty 1)
#define ICON_WIDTH			36	// ������ �ϳ� ���� ����
#define ICON_HEIGHT			36	// ������ �ϳ� ���� ����
#define BITPERPIX			12	// Pixel�� ��Ʈ ũ��

#define ICON_UPLEFT_X		FRAME_START_X
#define ICON_UPLEFT_Y		(FRAME_START_Y + 60)


#define PONG_ID				(IDB_BITMAP17 - 101) // Pong ������
#define EMPTY_ID			(IDB_BITMAP18 - 101) // Pong ���� ���������
#define START_BG_ID			(IDB_BITMAP19 - 101) // ���� �����̹���
#define END_BG_ID			(IDB_BITMAP20 - 101) // ���� �����̹���
#define GAME_FRAME_ID		(IDB_BITMAP24 - 101) // ���� ������ �̹���
#define START_BUTTON		(IDB_BITMAP23 - 101) //Start button
#define END_BUTTON			(IDB_BITMAP21 - 101)
#define RESTART_BUTTON		(IDB_BITMAP22 - 101)
#define SEC_FRAME			(IDB_BITMAP25 - 101)
#define SEC_EMPTY			(IDB_BITMAP26 - 101)

//#define IDB_BITMAP17 // Pong ������
//#define IDB_BITMAP18 // empty ������
//#define IDB_BITMAP19 // ���ӽ���ȭ��
//#define IDB_BITMAP20 // ��������ȭ��
//#define IDB_BITMAP21 // �׸��ϱ�
//#define IDB_BITMAP22 // ����۹�ư
//#define IDB_BITMAP23 // ���ӽ��۹�ư
//#define IDB_BITMAP24 // ����������
