// 14080018_2.2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Queue.h"
using namespace std;

template <class T>
void menu(Queue<T>& s)
{
	system("cls");
	int choice;
	cout << "����������ѡ��\n";
	cout << "1.�öӿ�\n";
	cout << "2.���\n";
	cout << "3.����\n";
	cout << "0.�˳�\n";
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
		s.InitQueue();
		system("pause");
		menu(s);
		break;
	case 2:
		int x;
		cin >> x;
		s.In(x);
		system("pause");
		menu(s);
		break;
	case 3:
		s.Out();
		system("pause");
		menu(s);
		break;
	case 0:
		exit(0);
		break;
	default:
		cout << "�������\n";
		system("pause");
		menu(s);
	}
}

int main()
{
	Queue<T> s;
	menu(s);
    return 0;
}

