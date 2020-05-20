#pragma once
#include<iostream>
using namespace std;
#include"wall.h"
#include"food.h"

class Snake
{
public:
	Snake(Wall& timewall,Food& timefood);

	struct Point  // struct ����һ������
	{
		// ������
		int x;
		int y;
		// ָ����
		Point* next;
	};

	enum              // ö�ټ��̲���
	{
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT='d'
	};

	void InitSnake(); //��ʼ����

	void DestroySnake();

	void AddSnake(int a,int b); // �����ߵĳ̶�

	void DeleteSnake();

	bool MoveSnake(char key);

	//�趨�Ѷ�
	int GetSleepTime();  // �����ߵ��ٶ��趨�� ������Խ�����ٶ�Խ�죬�������ٶȺ㶨

	// ��ȡ����Ķ���
	int CountSnake();

	// ��ȡ����
	int GetScore();


	Point * phead;  // ����ͷ�������ɾ�������

	Wall & wall;   // ��snake.h��ά��һ������wall,Ϊ�˵���Wall�еĶ���

	Food & food;
};