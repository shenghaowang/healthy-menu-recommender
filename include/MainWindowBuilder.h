#include <easyx.h>
#include "SWindow.h"

class MainWindowBuilder: SWindow
{
private:
    int width = 1000;
    int height = 800;
    int bkcolor = RGB(204, 255, 153);

public:
    MainWindowBuilder();
    ~MainWindowBuilder();
    static MainWindowBuilder* GetInstance()
	{
		static MainWindowBuilder MainWindowBuilder;
		return &MainWindowBuilder;
	}

public:
    void WindowDraw();
    void beginDraw();
    void endDraw();
};
