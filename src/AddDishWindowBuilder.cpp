#include <easyx.h>
#include "AddDishWindowBuilder.h"
#include "MainWindowBuilder.h"
#include "SPushButton.h"
#include "SWindow.h"


AddDishWindowBuilder::AddDishWindowBuilder(int width, int height):
    SWindow(width, height) {}

AddDishWindowBuilder::~AddDishWindowBuilder() {}

void AddDishWindowBuilder::WindowDraw()
{
    initgraph(640, 480);
    setbkcolor(RGB(256, 153, 102));
    cleardevice();

    SPushButton confirmBtn;

    confirmBtn.setTitle("Confirm");
    confirmBtn.move(500, 400);
    confirmBtn.show();

    while (true)
    {
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE))
        {
            confirmBtn.event(msg);
            if (confirmBtn.isClicked())
            {
                cleardevice();

                MainWindowBuilder main_wb = MainWindowBuilder(1000, 800);
                main_wb.WindowDraw();
            }
        }
    }
}