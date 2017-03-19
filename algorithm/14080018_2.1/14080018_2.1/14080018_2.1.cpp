// 14080018_2.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SeqStack.h"
#include "LinkStack.h"
using namespace std;

template <class T>
void main_menu()
{
	int choice;
	do
	{
		cout << "����������ѡ��\n";
		cout << "1.����˳��ջ\n";
		cout << "2.������ʽջ\n";
		cout << "0.��������\n";
		cin >> choice;
		if (choice == 1)
		{
			SeqStack<T> s;
			menu(s);
		}
		else if (choice == 2)
		{
			LinkStack<T> s;
			menu(s);
		}
		else if(choice != 0)
		{
			system("cls");
			cout << "�������\n";
			system("pause");
			system("cls");
		}
	} while (choice != 0);
	exit(0);
}

template <class T>
void menu(SeqStack<T>& s)
{
	system("cls");
	int choice;
	cout << "����������ѡ��\n";
	cout << "1.�ÿ�ջ\n";
	cout << "2.��ջ\n";
	cout << "3.��ջ\n";
	cout << "4.�鿴ջ��Ԫ��\n";
	cout << "0.�����ϲ�\n";
	cin >> choice;
	system("cls");
	switch (choice)
	{
		case 1:
			s.InitStack();
			system("pause");
			menu(s);
			break;
		case 2:
			int x;
			cin >> x;
			s.Push(x); 
			system("pause");
			menu(s);
			break;
		case 3:
			s.Pop();
			system("pause");
			menu(s);
			break;
		case 4:
			s.GetTop();
			system("pause");
			menu(s);
			break;
		case 0:
			return;
			break;
		default:
			cout << "�������\n";
			system("pause");
			menu(s);
	}
}

template <class T>
void menu(LinkStack<T>& s)
{
	system("cls");
	int choice;
	cout << "����������ѡ��\n";
	cout << "1.�ÿ�ջ\n";
	cout << "2.��ջ\n";
	cout << "3.��ջ\n";
	cout << "4.�鿴ջ��Ԫ��\n";
	cout << "0.�����ϲ�\n";
	cin >> choice;
	system("cls");
	switch (choice)
	{
		case 1:
			s.InitStack();
			system("pause");
			menu(s);
			break;
		case 2:
			int x;
			cin >> x;
			s.Push(x);
			system("pause");
			menu(s);
			break;
		case 3:
			s.Pop();
			system("pause");
			menu(s);
			break;
		case 4:
			s.GetTop();
			system("pause");
			menu(s);
			break;
		case 0:
			return;
			break;
		default:
			cout << "�������\n";
			system("pause");
			menu(s);
	}
}

int main()
{
	main_menu<T>();
}



