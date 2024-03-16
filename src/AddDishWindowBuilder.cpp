#include <easyx.h>
#include "AddDishWindowBuilder.h"
#include "DishManager.h"
#include "MainWindowBuilder.h"
#include "SPushButton.h"
#include "SWindow.h"


AddDishWindowBuilder::AddDishWindowBuilder():
    SWindow(this->width, this->height) {}

AddDishWindowBuilder::~AddDishWindowBuilder() {}

void AddDishWindowBuilder::WindowDraw()
{
    initgraph(this->width, this->height);
    setbkcolor(this->bkcolor);
    cleardevice();

    SPushButton confirmBtn, cancelBtn;

    confirmBtn.setTitle("Confirm");
    confirmBtn.move(350, 400);
    confirmBtn.show();

    cancelBtn.setTitle("Cancel");
    cancelBtn.move(500, 400);
    cancelBtn.show();

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

                MainWindowBuilder main_wb = MainWindowBuilder();
                main_wb.WindowDraw();
            }

            cancelBtn.event(msg);
            if (cancelBtn.isClicked())
            {
                cleardevice();

                MainWindowBuilder main_wb = MainWindowBuilder();
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

    settextcolor(RGB(52, 51, 51));
    settextstyle(17, 0, _T("Arial"));

    InputBox(dish_name, 50, "Please enter the dish name:");
    outtextxy(101, 10, dish_name);

    InputBox(ingredients, 1025, "Please enter the ingredients:");
    outtextxy(101, 60, ingredients);

    InputBox(calories, 10, "Please enter the calories:");
    outtextxy(101, 110, calories);

    InputBox(carbohydrates, 10, "Please enter the carbohydrates content:");
    outtextxy(101, 160, carbohydrates);

    InputBox(protein, 10, "Please enter the protein content:");
    outtextxy(101, 210, protein);

    InputBox(fat, 10, "Please enter the fat content:");
    outtextxy(101, 260, fat);

    InputBox(cellulose, 10, "Please enter the cellulose content:");
    outtextxy(101, 310, cellulose);

    InputBox(photo, 1025, "Please enter the directory of the dish photo:");
    outtextxy(101, 360, photo);

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
