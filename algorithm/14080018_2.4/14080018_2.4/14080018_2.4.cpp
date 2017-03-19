//MyStack.h
#include "stdafx.h"
#define MAXSIZE 100
using namespace std;

template <class ElemType> class MyStack
{
public:
	ElemType data[MAXSIZE];
	int top;

public:
	void init();            // ��ʼ��ջ
	bool empty();            // �ж�ջ�Ƿ�Ϊ��
	ElemType gettop();        // ��ȡջ��Ԫ��(����ջ)
	void push(ElemType x);    // ��ջ
	ElemType pop();            // ��ջ
};


template<class T> void MyStack<T>::init()
{
	this->top = 0;
}

template<class T> bool MyStack<T>::empty()
{
	return this->top == 0 ? true : false;
}

template<class T> T MyStack<T>::gettop()
{
	if (empty())
	{
		cout << "ջΪ�գ�\n";
		exit(1);
	}
	return this->data[this->top - 1];
}

template<class T> void MyStack<T>::push(T x)
{
	if (this->top == MAXSIZE)
	{
		cout << "ջ������\n";
		exit(1);
	}
	this->data[this->top] = x;
	this->top++;
}

template<class T> T MyStack<T>::pop()
{
	if (this->empty())
	{
		cout << "ջΪ��! \n";
		exit(1);
	}

	T e = this->data[this->top - 1];
	this->top--;
	return e;
}


bool isoperator(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return 1;
	default:
		return 0;
	}
}


int priority(char op)
{
	switch (op)
	{
	case '#':
		return -1;
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	default:
		return -1;
	}
}

//     ����׺���ʽת��Ϊ��׺���ʽ�����غ�׺���ʽ�ĳ��ȣ������ո�
void postfix(char pre[], char post[], int &n)
{
	int i = 0, j = 0;
	MyStack<char> stack;
	stack.init();        // ��ʼ���洢��������ջ

	stack.push('#');    // ���Ȱѽ�����־��#������ջ��

	while (pre[i] != '#')
	{
		if ((pre[i] >= '0' && pre[i] <= '9') || pre[i] == '.') // �������ֺ�С����ֱ��д���׺���ʽ
		{
			post[j++] = pre[i];
			n++;
		}
		else if (pre[i] == '(')    // �������������ñȽ�ֱ����ջ
			stack.push(pre[i]);
		else if (pre[i] == ')')  // ���������Ž����Ӧ�����ź�Ĳ�������������ջ�еģ�ȫ��д���׺���ʽ
		{
			while (stack.gettop() != '(')
			{
				post[j++] = stack.pop();
				n++;
			}
			stack.pop(); // ����������ջ����׺���ʽ�в���С����
		}
		else if (isoperator(pre[i]))
		{
			while (priority(pre[i]) <= priority(stack.gettop()))
			{
				// ��ǰ�Ĳ�����С�ڵ���ջ�������������ȼ�ʱ����ջ��������д�뵽��׺���ʽ���ظ��˹���
				post[j++] = stack.pop();
				n++;
			}

			stack.push(pre[i]);    // ��ǰ���������ȼ�����ջ�������������ȼ������ò�������ջ
		}

		i++;
	}
	while (stack.top) // �����еĲ����������׺���ʽ
	{
		post[j++] = stack.pop();
		n++;
	}
}

int main()
{
	char exp[100];
	cout << "������ʽ(��׺����#����)��";
	cin >> exp;
	char post[100];
	int n = 0;           
	postfix(exp, post, n);
	cout << "��׺���ʽΪ��";
	for (int i = 0; i < n - 1; i++)
		cout << post[i];
	cout << endl;
	system("pause");
	return 0;
}
