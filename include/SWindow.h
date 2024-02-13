#pragma once
#include <easyx.h>
#include <graphics.h>
#include "SObject.h"

class SWindow : public SObject 
{
public:
	SWindow(int w, int h, int flag = EW_SHOWCONSOLE);
	~SWindow();
	virtual void WindowDraw();

	// static void beginDraw();
	// static void endDraw();
	void beginDraw();
	void endDraw();
};

                      