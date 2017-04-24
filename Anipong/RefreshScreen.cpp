#include <iostream>
#include <windows.h>
#include "Common.h"
#include "Anipong.h"
unsigned int CALLBACK ThreadRefreshScreen(void* arg)
{
	char* pStr = (char*)arg;
	int i = 0;
	Anipong ap;
	GameFrame gf;
	Timer tm;
	
	while (1)
	{
	//	printf("%s ThreadRefreshScreen(%d)......\n", pStr, i++);
		//ap.displayIcons();
		//gf.showFrame();
		//ap.displayTimers();

		Sleep(10);
	
	}

	return 0;
}
