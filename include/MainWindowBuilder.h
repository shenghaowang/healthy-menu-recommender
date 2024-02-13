#include <easyx.h>
#include "SWindow.h"

class MainWindowBuilder: SWindow 
{
private:
    int width;
    int height;

public:
    MainWindowBuilder(int width, int height);
    ~MainWindowBuilder();
    
    void WindowDraw();
    void beginDraw();
    void endDraw();
};