#include "DishManager.h"

DishManager::DishManager()
{
	con = mysql_init(NULL);
	// declare character set
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	// if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	if (!mysql_real_connect(con, "127.0.0.1", "swang", "v34BiETMW380", "dev", 3306, NULL, 0))
	{ 
		std::cout << "Failed to connect" << std::endl;
		system("pause");
		exit(1);
	}
}                             

DishManager::~DishManager() 
{
	mysql_close(con);
}

bool DishManager::insertDish(Dish& dish)
{
	char sql[1025];
	sprintf(sql, "insert into dishes (dish_id, dish_name, ingredients, calories, carbohydrate, protein, fat, cellulose, photo) values(%d,'%s','%s',%d,%lf,%lf,%lf,%lf,'%s')",
		dish.dish_id, dish.dish_name.c_str(), dish.ingredients.c_str(), dish.calories, dish.carbohydrate, dish.protein, dish.fat, dish.cellulose, dish.photo.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to insert data : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool DishManager::updateDish(Dish& dish)
{
	char sql[1025];
	sprintf(sql, "UPDATE dishes SET dish_name='%s', ingredients='%s', calories=%d, carbohydrate=%lf, protein=%lf, fat=%lf, cellulose=%lf, photo='%s')"
		"WHERE dish_id = %d", dish.dish_id, dish.dish_name.c_str(), dish.ingredients.c_str(), dish.calories, dish.carbohydrate, dish.protein, dish.fat, dish.cellulose, dish.photo.c_str(),
		dish.dish_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to update data : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool DishManager::deleteDish(int dish_id)
{
	char sql[1025];
	sprintf(sql, "DELETE FROM dishes WHERE dish_id = %d", dish_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to delete data : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}


vector<Dish> DishManager::getDishes(string condition)
{
	vector<Dish> dishList;
	char sql[1025];
	sprintf(sql, "SELETE * FROM dishes %s ", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data : Error:%s\n", mysql_error(con));
		return {};
	}
    
	MYSQL_RES* res = mysql_store_result(con); // store query results
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res))) // fetch results row by row
	{
		Dish dish;
		dish.dish_id = atoi(row[1]);
		dish.dish_name = row[2];
		dish.ingredients = row[3];
		dish.calories = atoi(row[4]);
		dish.carbohydrate = atoi(row[5]);
		dish.protein = atoi(row[6]);
		dish.fat = atoi(row[7]);
		dish.cellulose = atoi(row[8]);
		dish.photo =row[9];
		 
		dishList.push_back(dish);
	}

	return dishList; // return list of dishes
}
