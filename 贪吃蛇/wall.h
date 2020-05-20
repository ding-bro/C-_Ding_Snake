#pragma once
#include<iostream>
using namespace std;

class Wall
{
public:
	//Wall()
	//{
	//	cout << "制作人：丁奕能" << endl;
	//	cout << "简易版snake" << endl;
	//}
	enum  // 枚举行数和列数
	{
		row = 40, // 行
		col = 80  // 列
	};

	void InitWall();  // 声明初始化墙壁函数
	void ShowWall();  //声明打印墙壁函数 

	void setwall(int a,int b,char c); // 设置snake，根据索引
	char getwall(int a,int b);  // 获取snake内容，根据索引


private:
	char wallarray[row][col];  // 定义一个二维数组,创建墙
};