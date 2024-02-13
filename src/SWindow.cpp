#include "SWindow.h"

SWindow::SWindow(int w, int h, int flag)
{
	initgraph(w, h, flag);
}

SWindow::~SWindow()
{
	
	system("pause");
}

void SWindow::WindowDraw()
{
	
	setbkcolor(RGB(204, 255, 153));
	cleardevice();
	
}

void SWindow::beginDraw()
{
	BeginBatchDraw();
}

void SWindow::endDraw()
{
	EndBatchDraw();
}
