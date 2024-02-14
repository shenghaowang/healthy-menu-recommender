#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <mysql/mysql.h>

using namespace std;


typedef struct Dish
{
	int dish_id;
	string dish_name;
	string ingredients;
	int calories;
	double carbohydrate;
	double protein;
	double fat;
	double cellulose;
	string photo;
} Dish;

class DishManager
{
public:
	DishManager();
	~DishManager();
	static DishManager* GetInstance()
	{
		static DishManager DishManager;
		return &DishManager;
	}

public:
	bool insertDish(Dish& t);
	bool updateDish(Dish& t);
	bool deleteDish(int dish_id);
	vector<Dish> getDishes(string condition = "");
	
private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "swang";
	const char* pw = "v34BiETMW380";
	const char* database_name = "dev";
	const int port = 3306;

};
