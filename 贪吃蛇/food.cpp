#include"food.h"
#include"wall.h"
#include"snake.h"

Food::Food(Wall& timewall):food(timewall) // 这种写法是初始化列表
{

}

void Food::setfood()
{
	while (true)
	{
		// 前后两行两列是终线，食物不可以出现
		FoodX = rand() % (Wall::row - 2) + 1;  // rand()%12 :0-11  rand()%13:  0-12    rand特性
		FoodY = rand() % (Wall::col - 2) + 1;


		if (food.getwall(FoodX, FoodY) == ' ')  // 食物不能出现在snake身上，如果getwall返回的值==空格，说明没遇到snake
		{
			food.setwall(FoodX, FoodY, '@');
		}
		break;  // 如果是空格，break掉，如果不是空格，重新再循环写一遍，直到遇见空格
	}
}