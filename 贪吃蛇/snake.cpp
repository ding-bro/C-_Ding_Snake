#pragma once
#include"snake.h"
#include"wall.h"
#include<Windows.h>

/*
A( int aa, int bb ):a(aa),b(bb)    // ��ʼ���б�д��
{

}

�൱��
A( int aa, int bb )
{
a=aa;
b=bb;
}
*/

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������,�������ֻ����ÿ��ͷ�ļ��е����������ͺ�����������Ч
void gotoxy1(HANDLE hOut1, int x, int y)//����x��y������������෴�ģ�ע������
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut1, pos);
}//��궨λ����




Snake::Snake(Wall & timewall,Food & timefood):wall(timewall),food(timefood)  // ����д���ǳ�ʼ���б�
{
	// wall=timewall
	// food=timefood
	phead = NULL;  // һ��ʼ��ͷ���϶���Ϊ�յ�
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

void Snake::DestroySnake()  // ɾ���ı��ʾ��Ǹ��ǣ�ͷ���ָ��
{
	Point * tpoint = phead;   // ����һ����ʱ�ڵ�ָ��ͷ���
	while (phead != NULL)  // ��ͷ��㲻Ϊ�յ�ʱ��ʼ����
	{
		tpoint = phead->next;  // ��ʱ�ڵ��Ѿ�����ͷ��� �� ��ʱ�ڵ���ָ��ͷ����next�ڵ�ﵽ�˸���Ч��
		delete phead;  // �ͷ�ͷ���
		phead = tpoint;   // ����ʱ�ڵ���ͷ���
	}
}

void Snake::AddSnake(int a,int b)
{
	Point* newpoint=new Point; // ��ӽڵ�϶�Ҫ����һ���½ڵ�
	newpoint->x = a;
	newpoint->y = b;
	newpoint->next = NULL;

	if (phead!=NULL)  // ��ͷ��㲻Ϊ�յ�����½��в���
	{
		// Ҫ����setwall,��Ҫ��.h��ά��wall
		// �õ���ͬһ��wall
		wall.setwall(phead->x, phead->y, '+');  // ����setwall���и��ǣ�ԭ����snake�� --# �����Ҫ��ӽڵ㣬��'#'���ǳ�'-',��ʱsnakeΪ��---

		//gotoxy1(hOut1, phead->y,phead->x);   // ���������޸�
		//cout << "+";  // ���Ĵ�ӡ

	}
	newpoint->next = phead;  // ����newpoint��next�ڵ�ָ��ԭ����ͷ���

	phead = newpoint;  // ����ͷ���

	wall.setwall(phead->x, phead->y, '#');  // setwall��ͷ�����'#',��ʱsnakeΪ�� ---#, ��ӽڵ�ɹ�

	//gotoxy1(hOut1, phead->y, phead->x);
	//cout << "#";
}

void Snake::DeleteSnake()
{
	if (phead==NULL||phead->next==NULL)
	{
		return;
	}
	Point* Pcurrent = phead->next;  // ����һ����ǰ�ڵ�ָ��ͷ����next
	Point* Pprevious = phead;  // ������һ���ڵ�ָ��phead
	// �����ڵ�ͬʱ����
	// ��Pcurrent��next�ڵ㲻����NULLʱ������ɾ������
	// ����һ���ڵ�Ppreviousָ��Pprevious��next�ڵ㣬���и���Pcurrent
	// ��Pcurrentָ��Pcurrent��next�ڵ�
	// ������setwall��Pcurrent->next ��������Ϊ�ո�
	// ��Pcurrent���ڴ�ɾ��

	while (Pcurrent->next!=NULL)
	{
		Pprevious = Pprevious->next;  // ���Ⱥ�˳��
		Pcurrent = Pcurrent->next;
	}

	// ɾ��β���
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

	switch (key)   // �������ڵ����������һ��excel��񣬷�Ϊx���y��
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

	if (wall.getwall(x, y) == '*' || wall.getwall(x, y) == '+')  // ����ǽ������������ʧ��
	{
		cout << "GAME OVER !" << endl;
		return false;
	}

	// �߳Ե�ʳ��ʱ��
	if (wall.getwall(x,y)=='@')
	{
		AddSnake(x, y);

		// �Ե�ʳ��֮��Ҫ��������ʳ��
		food.setfood();
	}
	// ��û�гԵ�ʳ��ʱ��
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
	int size = CountSnake();  // ����ĳ��Ⱦ���CountSnake����
	if (size<8)  // 
	{
		sleeptime = 100;
	}
	else if (size>8&&size<12)    // ��Ļˢ��ʱ��ԽС���ٶ�Խ��
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
	int snakesize = 0;  // ��ʼ���ߵĳ���
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
	int score = (size - 3) * 10;  // �����һ��food��10��
	return score; 
}