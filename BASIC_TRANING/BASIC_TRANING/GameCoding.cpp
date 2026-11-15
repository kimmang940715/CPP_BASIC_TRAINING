#include <iostream>
using namespace std;
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <windows.h>

int main_()
{
	SetCursorOnOff(false);

	while (true)
	{
		// 입력
		HandleKeyInput();

		// 로직
		HandleMove();

		// 출력
		PrintMap2D();
	}
}