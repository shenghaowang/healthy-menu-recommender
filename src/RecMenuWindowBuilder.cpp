#include <easyx.h>
#include "RecMenuWindowBuilder.h"
#include "SPushButton.h"
#include "SWindow.h"


RecMenuWindowBuilder::RecMenuWindowBuilder(int width, int height):
    SWindow(width, height) {}

RecMenuWindowBuilder::~RecMenuWindowBuilder() {}

void RecMenuWindowBuilder::WindowDraw()
{
    initgraph(640, 480);
    setbkcolor(RGB(256, 153, 102));
    cleardevice();

    SPushButton recBtn;

    recBtn.setTitle("Recommend");
    recBtn.move(500, 400);
    recBtn.show();
}