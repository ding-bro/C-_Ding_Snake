#include"food.h"
#include"wall.h"
#include"snake.h"

Food::Food(Wall& timewall):food(timewall) // ����д���ǳ�ʼ���б�
{

}

void Food::setfood()
{
	while (true)
	{
		// ǰ���������������ߣ�ʳ�ﲻ���Գ���
		FoodX = rand() % (Wall::row - 2) + 1;  // rand()%12 :0-11  rand()%13:  0-12    rand����
		FoodY = rand() % (Wall::col - 2) + 1;


		if (food.getwall(FoodX, FoodY) == ' ')  // ʳ�ﲻ�ܳ�����snake���ϣ����getwall���ص�ֵ==�ո�˵��û����snake
		{
			food.setwall(FoodX, FoodY, '@');
		}
		break;  // ����ǿո�break����������ǿո�������ѭ��дһ�飬ֱ�������ո�
	}
}