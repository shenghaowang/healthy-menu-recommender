#include <easyx.h>
#include "SWindow.h"

class RecMenuWindowBuilder: SWindow
{
private:
    int weight;
    int height;

public:
    RecMenuWindowBuilder(int width, int height);
    ~RecMenuWindowBuilder();

    void WindowDraw();
    void beginDraw();
    void endDraw();
};