#include <easyx.h>
#include "SWindow.h"
#include "DishManager.h"

class AddDishWindowBuilder: SWindow
{
private:
    int width = 900;
    int height = 500;
    int bkcolor = RGB(192, 192, 192);

public:
    AddDishWindowBuilder();
    ~AddDishWindowBuilder();

    void WindowDraw();
    void beginDraw();
    void endDraw();

    Dish enterDishInfo();
};
