#include <easyx.h>
#include <algorithm>
#include "DishManager.h"
#include "RecMenuWindowBuilder.h"
#include "MainWindowBuilder.h"
#include "SPushButton.h"
#include "SWindow.h"


const int numDishesToRecommend = 3;

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

                vector<Dish> recommendedDishes = this->recommendDishes(requiredNutrition);

                settextcolor(RGB(52, 51, 51));
                settextstyle(17, 0, _T("Arial"));

                int numDishes = recommendedDishes.size();
                // outtextxy(80, 230, string("Number of dishes: ").append(to_string(numDishes)).c_str());

                if (numDishes == numDishesToRecommend)
                {
                    IMAGE dishImg;

                    outtextxy(80, 60, string("3 dishes have been recommended as per request:").c_str());
                    outtextxy(80, 90, string("Dish 1 recommended: ").append(recommendedDishes[0].dish_name).c_str());
                    outtextxy(80, 120, string("Ingredients to prepare: ").append(recommendedDishes[0].ingredients).c_str());
                    loadimage(&dishImg, recommendedDishes[0].photo.c_str(), 120, 100);
                    putimage(80, 150, &dishImg);

                    outtextxy(80, 280, string("Dish 2 recommended: ").append(recommendedDishes[1].dish_name).c_str());
                    outtextxy(80, 310, string("Ingredients to prepare: ").append(recommendedDishes[1].ingredients).c_str());
                    loadimage(&dishImg, recommendedDishes[1].photo.c_str(), 120, 100);
                    putimage(80, 340, &dishImg);

                    outtextxy(80, 470, string("Dish 3 recommended: ").append(recommendedDishes[2].dish_name).c_str());
                    outtextxy(80, 500, string("Ingredients to prepare: ").append(recommendedDishes[1].ingredients).c_str());
                    loadimage(&dishImg, recommendedDishes[2].photo.c_str(), 120, 100);
                    putimage(80, 530, &dishImg);

                } else {
                    outtextxy(80, 100, string("Unfortunately no dish combo can fulfill your requirement.").c_str());
                }
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

void generateDishCombos(const vector<Dish>& allDishes, vector<Dish>& dishCombo, int start, int n, int r, vector<vector<Dish>>& res)
{
    if (r == 0) {
        res.push_back(dishCombo);
        return;
    }

    for (int i = start; i <= n - r; ++i) {
        dishCombo.push_back(allDishes[i]);
        generateDishCombos(allDishes, dishCombo, i+1, n, r-1, res);
        dishCombo.pop_back();
    }
}

vector<Dish> RecMenuWindowBuilder::recommendDishes(Nutrition requiredNutrition)
{
    // Extract all dishes
    vector<Dish> allDishes = DishManager::GetInstance()->getDishes("");

    // Randomly shuffle the dish combos
    std::random_shuffle (allDishes.begin(), allDishes.end());

    // Generate all dish combinations
    int numUniqDishes = allDishes.size();
    vector<vector<Dish>> allDishCombos;
    vector<Dish> dishCombo;
    generateDishCombos(allDishes, dishCombo, 0, numUniqDishes, numDishesToRecommend, allDishCombos);

    int numDishCombos = allDishCombos.size();
    // outtextxy(80, 200, string("Number of dish combos: ").append(to_string(numDishCombos)).c_str());

    for (unsigned int i = 0; i < numDishCombos; i++)
	{
        vector<Dish> menu = allDishCombos[i];

        // Sum up the nutrition of all dishes
        int totalCalories = menu[0].calories + menu[1].calories + menu[2].calories;
        double totalCarbohydrates = menu[0].carbohydrate + menu[1].carbohydrate + menu[2].carbohydrate;
        double totalProtein = menu[0].protein + menu[1].protein + menu[2].protein;
        double totalFat = menu[0].fat + menu[1].fat + menu[2].fat;
        double totalCellulose = menu[0].cellulose + menu[1].cellulose + menu[2].cellulose;

        // Validate individual menu
        if ((requiredNutrition.calories <= totalCalories) && \
            (requiredNutrition.carbohydrate <= totalCarbohydrates) && \
            (requiredNutrition.protein <= totalProtein) && \
            (requiredNutrition.fat <= totalFat) && \
            (requiredNutrition.cellulose <= totalCellulose))

            return menu;
	}

    return vector<Dish>();
}
