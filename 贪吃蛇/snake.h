#pragma once
#include<iostream>
using namespace std;
#include"wall.h"
#include"food.h"

class Snake
{
public:
	Snake(Wall& timewall,Food& timefood);

	struct Point  // struct 创建一个链表
	{
		// 数据域
		int x;
		int y;
		// 指针域
		Point* next;
	};

	enum              // 枚举键盘操作
	{
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT='d'
	};

	void InitSnake(); //初始化蛇

	void DestroySnake();

	void AddSnake(int a,int b); // 增加蛇的程度

	void DeleteSnake();

	bool MoveSnake(char key);

	//设定难度
	int GetSleepTime();  // 根据蛇的速度设定； 蛇身长度越长，速度越快，最后最快速度恒定

	// 获取蛇身的段落
	int CountSnake();

	// 获取分数
	int GetScore();


	Point * phead;  // 创建头结点用于删除和添加

	Wall & wall;   // 在snake.h中维护一个对象wall,为了调用Wall中的对象

	Food & food;
};