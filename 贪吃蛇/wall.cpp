#pragma once
#include"wall.h"


void Wall::InitWall()  // 初始化墙壁
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i==0||j==0||i==row-1||j==col-1)
			{
				wallarray[i][j] = '*';
			}
			else
			{
				wallarray[i][j] = ' ';
			}
		}
	}
}

void Wall::ShowWall()   // 打印墙壁框架
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << wallarray[i][j];
		}
		if (i==5)
		{
			cout << "	制作人：丁奕能";
		}
		if (i==6)
		{
			cout << "	玩法操作:";
		}
		if (i==7)
		{
			cout << "	w	上";
		}
		if (i==8)
		{
			cout << "	s	下";
		}
		if (i==9)
		{
			cout << "	a	左";
		}
		if (i==10)
		{
			cout << "	d	右";
		}
		if (i==11)
		{
			cout << "	蛇：++#";
		}
		if (i==12)
		{
			cout << "	食物：@";
		}

		cout << endl;
	}

}

void Wall::setwall(int a,int b,char c)
{
	wallarray[a][b] = c;
}

char Wall::getwall(int a, int b)
{
	return wallarray[a][b];
}
