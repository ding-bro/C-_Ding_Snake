#pragma once
#include"wall.h"


void Wall::InitWall()  // ��ʼ��ǽ��
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

void Wall::ShowWall()   // ��ӡǽ�ڿ��
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << wallarray[i][j];
		}
		if (i==5)
		{
			cout << "	�����ˣ�������";
		}
		if (i==6)
		{
			cout << "	�淨����:";
		}
		if (i==7)
		{
			cout << "	w	��";
		}
		if (i==8)
		{
			cout << "	s	��";
		}
		if (i==9)
		{
			cout << "	a	��";
		}
		if (i==10)
		{
			cout << "	d	��";
		}
		if (i==11)
		{
			cout << "	�ߣ�++#";
		}
		if (i==12)
		{
			cout << "	ʳ�@";
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
