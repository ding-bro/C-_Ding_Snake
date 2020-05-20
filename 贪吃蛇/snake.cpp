#pragma once
#include"snake.h"
#include"wall.h"
#include<Windows.h>

/*
A( int aa, int bb ):a(aa),b(bb)    // 初始化列表写法
{

}

相当于
A( int aa, int bb )
{
a=aa;
b=bb;
}
*/

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
void gotoxy1(HANDLE hOut1, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut1, pos);
}//光标定位函数




Snake::Snake(Wall & timewall,Food & timefood):wall(timewall),food(timefood)  // 这种写法是初始化列表
{
	// wall=timewall
	// food=timefood
	phead = NULL;  // 一开始的头结点肯定是为空的
}

void Snake::InitSnake()
{
	DestroySnake();
	AddSnake(10, 15);
	AddSnake(10, 16);	
	AddSnake(10, 17);
	//AddSnake(5, 3);
	//AddSnake(5, 4);
	//AddSnake(5, 5);

}

void Snake::DestroySnake()  // 删除的本质就是覆盖，头结点指向
{
	Point * tpoint = phead;   // 创建一个临时节点指向头结点
	while (phead != NULL)  // 当头结点不为空的时候开始操作
	{
		tpoint = phead->next;  // 临时节点已经等于头结点 ， 临时节点又指向头结点的next节点达到了覆盖效果
		delete phead;  // 释放头结点
		phead = tpoint;   // 让临时节点变成头结点
	}
}

void Snake::AddSnake(int a,int b)
{
	Point* newpoint=new Point; // 添加节点肯定要创建一个新节点
	newpoint->x = a;
	newpoint->y = b;
	newpoint->next = NULL;

	if (phead!=NULL)  // 在头结点不为空的情况下进行操作
	{
		// 要调用setwall,就要在.h中维护wall
		// 拿到了同一个wall
		wall.setwall(phead->x, phead->y, '+');  // 利用setwall进行覆盖，原来的snake是 --# ，如果要添加节点，把'#'覆盖成'-',此时snake为：---

		//gotoxy1(hOut1, phead->y,phead->x);   // 光标的适配修改
		//cout << "+";  // 光标的打印

	}
	newpoint->next = phead;  // 再让newpoint的next节点指向原来的头结点

	phead = newpoint;  // 更新头结点

	wall.setwall(phead->x, phead->y, '#');  // setwall让头结点变成'#',此时snake为： ---#, 添加节点成功

	//gotoxy1(hOut1, phead->y, phead->x);
	//cout << "#";
}

void Snake::DeleteSnake()
{
	if (phead==NULL||phead->next==NULL)
	{
		return;
	}
	Point* Pcurrent = phead->next;  // 创建一个当前节点指向头结点的next
	Point* Pprevious = phead;  // 创建上一个节点指向phead
	// 两个节点同时遍历
	// 当Pcurrent的next节点不等于NULL时，进行删除覆盖
	// 将上一个节点Pprevious指向Pprevious的next节点，进行覆盖Pcurrent
	// 将Pcurrent指向Pcurrent的next节点
	// 再利用setwall把Pcurrent->next 的数据置为空格
	// 将Pcurrent的内存删除

	while (Pcurrent->next!=NULL)
	{
		Pprevious = Pprevious->next;  // 有先后顺序
		Pcurrent = Pcurrent->next;
	}

	// 删除尾结点
	wall.setwall(Pcurrent->x, Pcurrent->y,' ');

	//gotoxy1(hOut1, phead->y, phead->x);
	//cout << " ";

	delete Pcurrent;
	Pcurrent = NULL;
	Pprevious->next = NULL;
}

bool Snake::MoveSnake(char key)
{
	int x = phead->x;
	int y = phead->y;

	switch (key)   // 将蛇所在的区域想象成一个excel表格，分为x轴和y轴
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	if (wall.getwall(x, y) == '*' || wall.getwall(x, y) == '+')  // 碰到墙或者碰到蛇身都失败
	{
		cout << "GAME OVER !" << endl;
		return false;
	}

	// 蛇吃到食物时：
	if (wall.getwall(x,y)=='@')
	{
		AddSnake(x, y);

		// 吃掉食物之后要重新设置食物
		food.setfood();
	}
	// 蛇没有吃到食物时：
	else
	{
		AddSnake(x, y);
		DeleteSnake();
	}
	return true;
}

int Snake::GetSleepTime()
{
	int sleeptime = 0;
	int size = CountSnake();  // 蛇身的长度就用CountSnake计算
	if (size<8)  // 
	{
		sleeptime = 100;
	}
	else if (size>8&&size<12)    // 屏幕刷新时间越小，速度越快
	{
		sleeptime = 50;
	}
	else
	{
		sleeptime = 30;
	}
	return sleeptime;
}

int Snake::CountSnake()
{
	int snakesize = 0;  // 初始化蛇的长度
	Point* currentpoint = phead;
	while (currentpoint!=NULL)
	{
		snakesize++;
		currentpoint = currentpoint->next;
	}
	return snakesize;
}

int Snake::GetScore()
{
	int size = CountSnake();
	int score = (size - 3) * 10;  // 假设吃一个food是10分
	return score; 
}