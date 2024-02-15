#include <string>
#include <vector>
#include <easyx.h>
#include "MainWindowBuilder.h"
#include "SPushButton.h"
#include "SWindow.h"
#include "RecMenuWindowBuilder.h"
#include "AddDishWindowBuilder.h"
#include "DishManager.h"


#define MAX_NUM_DISHES 40


MainWindowBuilder::MainWindowBuilder(int width, int height):
    SWindow(width, height) {}

MainWindowBuilder::~MainWindowBuilder() {}

void MainWindowBuilder::beginDraw() {
    SWindow::beginDraw();
}

void MainWindowBuilder::endDraw() {
    SWindow::endDraw();
}

void MainWindowBuilder::WindowDraw()
{
    initgraph(1000, 800);
    setbkcolor(RGB(204, 255, 153));
    cleardevice();

    SPushButton recMenuBtn, addDishBtn;
    
    recMenuBtn.setTitle("Recommend menu");
    recMenuBtn.move(150, 0);
    addDishBtn.setTitle("Add new dish");
    addDishBtn.move(300, 0);

    // Load dishes from database
    char fetchDishesCondition[1025];
    sprintf(fetchDishesCondition, "WHERE dish_id < '%d'", MAX_NUM_DISHES);

    // recMenuBtn.show();
    // addDishBtn.show();

    // vector<Dish> dishes = DishManager::GetInstance()->getDishes(fetchDishesCondition);
    vector<Dish> dishes = DishManager::GetInstance()->getDishes();

    IMAGE dishImg;
	for (unsigned int i = 0; i < MAX_NUM_DISHES; i++)
	{
		// char filename[100];
		// sprintf(filename, "C:\\Users\\vboxuser\\Desktop\\img\\img%d.jpg", i + 1);
		// loadimage(&dishImg, filename, 120, 100);

        cout << dishes[i].photo.c_str() << endl;

        loadimage(&dishImg, dishes[i].photo.c_str(), 120, 100);
		putimage(150 * (i%6) + 30, 80 + 100 * (i/6), &dishImg);
	}

    recMenuBtn.show();
    addDishBtn.show();

    while (true)
    {
        ExMessage mouseMsg;
        if (peekmessage(&mouseMsg, EM_MOUSE))
        {
            recMenuBtn.event(mouseMsg);
            if (recMenuBtn.isClicked())
            {
                RecMenuWindowBuilder rec_menu_wb = RecMenuWindowBuilder(640, 480);

                cleardevice();
                rec_menu_wb.WindowDraw();
            }

            addDishBtn.event(mouseMsg);
            if (addDishBtn.isClicked())
            {
                AddDishWindowBuilder add_dish_wb = AddDishWindowBuilder(640, 480);

                cleardevice();
                add_dish_wb.WindowDraw();
            }
        }
    }

    getchar();
	system("pause");
};