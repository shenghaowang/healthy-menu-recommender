#include <easyx.h>
#include "DishManager.h"
#include "RecMenuWindowBuilder.h"
#include "MainWindowBuilder.h"
#include "SPushButton.h"
#include "SWindow.h"


RecMenuWindowBuilder::RecMenuWindowBuilder():
    SWindow(this->width, this->height) {}

RecMenuWindowBuilder::~RecMenuWindowBuilder() {}

void RecMenuWindowBuilder::WindowDraw()
{
    initgraph(this->width, this->height);
    setbkcolor(this->bkcolor);
    cleardevice();

    SPushButton recBtn, returnBtn;

    recBtn.setTitle("Recommend");
    recBtn.move(350, 400);
    recBtn.show();

    returnBtn.setTitle("Return");
    returnBtn.move(500, 400);
    returnBtn.show();

    Nutrition requiredNutrition = this->enterRequiredNutrition();

    while (true)
    {
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE))
        {
            recBtn.event(msg);
            if (recBtn.isClicked())
            {
                cleardevice();

                vector<Dish> recommendedDishes = this->recommendDishes();

                settextcolor(RGB(52, 51, 51));
                settextstyle(17, 0, _T("Arial"));

                int numDishes = recommendedDishes.size();
                outtextxy(80, 200, string("Number of dishes: ").append(to_string(numDishes)).c_str());
            }

            returnBtn.event(msg);
            if (returnBtn.isClicked())
            {
                cleardevice();

                MainWindowBuilder main_wb = MainWindowBuilder();
                main_wb.WindowDraw();
            }
        }
    }
}

Nutrition RecMenuWindowBuilder::enterRequiredNutrition()
{
    char calories[10];
    char carbohydrates[10];
    char protein[10];
    char fat[10];
    char cellulose[10];

    settextcolor(RGB(52, 51, 51));
    settextstyle(17, 0, _T("Arial"));

    outtextxy(80, 60, string("Please enter the required nutrition intakes on a daily basis.").c_str());

    InputBox(calories, 10, "Please enter the daily required calories:");
    outtextxy(80, 110, string("Calories: ").append(calories).c_str());

    InputBox(carbohydrates, 10, "Please enter the daily required carbohydrates:");
    outtextxy(280, 110, string("Carbohydrates: ").append(carbohydrates).c_str());

    InputBox(protein, 10, "Please enter the daily protein:");
    outtextxy(80, 140, string("Protein: ").append(protein).c_str());

    InputBox(fat, 10, "Please enter the daily required fat:");
    outtextxy(280, 140, string("Fat: ").append(fat).c_str());

    InputBox(cellulose, 10, "Please enter the daily required cellulose:");
    outtextxy(80, 170, string("Cellulose: ").append(cellulose).c_str());

    Nutrition nutrition;
    nutrition.calories = atoi(calories);
    nutrition.carbohydrate = atof(carbohydrates);
    nutrition.protein = atof(protein);
    nutrition.fat = atof(fat);
    nutrition.cellulose = atof(cellulose);

    return nutrition;
}

vector<Dish> RecMenuWindowBuilder::recommendDishes()
{
    vector<Dish> allDishes = DishManager::GetInstance()->getDishes("");

    return allDishes;
}
