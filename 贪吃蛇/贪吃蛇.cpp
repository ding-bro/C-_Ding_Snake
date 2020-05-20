#include<iostream>
using namespace std;
#include"wall.h"
#include"snake.h"
#include<ctime>
#include"food.h"
#include<conio.h>
#include<Windows.h>

// 游戏优化，利用光标定位在蛇的身上，就不用再刷屏，解决刷屏问题
void gotoxy(HANDLE hOut, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}//光标定位函数
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效

int main()
{
	cout << "请按w,s,d任意按键激活游戏！" << endl;
	Wall w;
	Food f(w);
	Snake s(w, f);

	w.InitWall();
	//w.ShowWall();

	// 测试代码  设置和获取
	//w.setwall(3,3,'-');
	//w.setwall(3, 4, '-');
	//w.setwall(3, 5, '#');
	//w.ShowWall();
	//cout << w.getwall(3,3) << endl;

	//s.DeleteSnake();
	//w.ShowWall();

	srand(time(NULL));
	f.setfood();

	s.InitSnake();

	w.ShowWall();
	//gotoxy(hOut, 0, Wall::row);

	//gotoxy(hOut, 5, 5);

	// snake的第一步移动
	//char key =_getch();
	//if (s.MoveSnake(key)==true)
	//{
	//	system("pause");
	//	w.ShowWall();
	//	Sleep(300);
	//}

	bool dead = false;   // 记录snake的死亡

	char prekey = NULL;  // 创建上一个按键

	while (!dead)
	{
		char key = _getch();
		do
		{
			if (key==s.UP||key==s.DOWN||key==s.LEFT||key==s.RIGHT)
			{

				if (key==s.UP && prekey==s.DOWN||      // 解决冲突按键bug
					key==s.DOWN && prekey ==s.UP||
					key==s.LEFT && prekey ==s.RIGHT||
					key==s.RIGHT && prekey ==s.LEFT)
				{
					key = prekey;   // 如果按键冲突，强制让key变为上一次的按键
				}
				else
				{
					prekey = key;   // 如果没有冲突，就更新按键
				}

				// prekey = key;    取消暂停效果    更新按键

				if (s.MoveSnake(key) == true)
				{
					system("cls");
					w.ShowWall();
					//gotoxy(hOut, 0, Wall::row);
					
					cout << "Snake的得分为：" << s.GetScore()<<"分" << endl;
					Sleep(s.GetSleepTime());
				}
				else
				{
					dead = true;
					break;
				}
			}
			else
			{
				key = prekey;
			}

		} while (!_kbhit());  // 当没有键盘输入时，返回0
	}

	cout << s.CountSnake() << endl;;

	system("pause");
	return 0;
}

