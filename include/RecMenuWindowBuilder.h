#include <easyx.h>
#include "SWindow.h"
#include "DishManager.h"

using namespace std;

typedef struct Nutrition
{
	int calories;
	double carbohydrate;
	double protein;
	double fat;
	double cellulose;
} Nutrition;


class RecMenuWindowBuilder: SWindow
{
private:
    int width = 1200;
    int height = 900;
    int bkcolor = RGB(256, 153, 102);

public:
    RecMenuWindowBuilder();
    ~RecMenuWindowBuilder();

    void WindowDraw();
    void beginDraw();
    void endDraw();

    Nutrition enterRequiredNutrition();
    vector<Dish> recommendDishes(Nutrition requiredNutrition);
};
