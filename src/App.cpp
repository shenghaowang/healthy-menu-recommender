#include <iostream>
#include <graphics.h>
#include <easyx.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "MainWindowBuilder.h"

using namespace std;

#pragma warning( disable : 4996 )


int main()
{
	
	MainWindowBuilder main_wb = MainWindowBuilder(1000, 800);
	
	// main_wb.beginDraw();
	main_wb.WindowDraw();
	main_wb.beginDraw();
	main_wb.endDraw();

	system("pause");
		
}
 