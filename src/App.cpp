#include <iostream>
#include <graphics.h>
#include <easyx.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "DishManager.h"
#include "MainWindowBuilder.h"

using namespace std;

int main()
{

	MainWindowBuilder main_wb = MainWindowBuilder();

	// main_wb.beginDraw();
	main_wb.WindowDraw();
	main_wb.beginDraw();
	main_wb.endDraw();

	getchar();
	system("pause");

}
