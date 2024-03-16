#include <easyx.h>
#include "SWindow.h"
#include "DishManager.h"

class AddDishWindowBuilder: SWindow
{
private:
    int width = 640;
    int height = 480;
    int bkcolor = RGB(256, 153, 102);

public:
    AddDishWindowBuilder();
    ~AddDishWindowBuilder();

    void WindowDraw();
    void beginDraw();
    void endDraw();

    Dish enterDishInfo();
};
