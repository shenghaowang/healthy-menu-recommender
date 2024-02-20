#include <easyx.h>
#include "SWindow.h"
#include "DishManager.h"

class AddDishWindowBuilder: SWindow
{
private:
    int width;
    int height;

public:
    AddDishWindowBuilder(int width, int height);
    ~AddDishWindowBuilder();

    void WindowDraw();
    void beginDraw();
    void endDraw();

    Dish enterDishInfo();
};
