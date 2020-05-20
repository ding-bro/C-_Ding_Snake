#pragma once
#include <iostream>
using namespace std;
#include"wall.h"


class Food
{
public:
	Food(Wall& timewall);

	void setfood();
	int FoodX;
	int FoodY;
	
	

	Wall& food;
};