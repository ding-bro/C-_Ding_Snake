#pragma once
#include<iostream>
using namespace std;

class Wall
{
public:
	//Wall()
	//{
	//	cout << "�����ˣ�������" << endl;
	//	cout << "���װ�snake" << endl;
	//}
	enum  // ö������������
	{
		row = 40, // ��
		col = 80  // ��
	};

	void InitWall();  // ������ʼ��ǽ�ں���
	void ShowWall();  //������ӡǽ�ں��� 

	void setwall(int a,int b,char c); // ����snake����������
	char getwall(int a,int b);  // ��ȡsnake���ݣ���������


private:
	char wallarray[row][col];  // ����һ����ά����,����ǽ
};