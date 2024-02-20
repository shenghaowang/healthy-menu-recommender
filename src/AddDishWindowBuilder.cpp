#include <easyx.h>
#include "AddDishWindowBuilder.h"
#include "DishManager.h"
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

    Dish newDish = this->enterDishInfo();

    while (true)
    {
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE))
        {
            confirmBtn.event(msg);
            if (confirmBtn.isClicked())
            {
                cleardevice();

                DishManager::GetInstance()->insertDish(newDish);

                MainWindowBuilder main_wb = MainWindowBuilder(1000, 800);
                main_wb.WindowDraw();
            }
        }
    }
}

Dish AddDishWindowBuilder::enterDishInfo()
{
    char dish_name[50];
    char ingredients[1025];
    char calories[10];
    char carbohydrates[10];
    char protein[10];
    char fat[10];
    char cellulose[10];
    char photo[1025];

    InputBox(dish_name, 50, "Please enter the dish name:");
    InputBox(ingredients, 1025, "Please enter the ingredients:");
    InputBox(calories, 10, "Please enter the calories:");
    InputBox(carbohydrates, 10, "Please enter the carbohydrates content:");
    InputBox(protein, 10, "Please enter the protein content:");
    InputBox(fat, 10, "Please enter the fat content:");
    InputBox(cellulose, 10, "Please enter the cellulose content:");
    InputBox(photo, 1025, "Please enter the directory of the dish photo:");

    Dish dish;
    dish.dish_name = dish_name;
    dish.ingredients = ingredients;
    dish.calories = atoi(calories);
    dish.carbohydrate = atof(carbohydrates);
    dish.protein = atof(protein);
    dish.fat = atof(fat);
    dish.cellulose = atof(cellulose);
    dish.photo = photo;

    return dish;
}
