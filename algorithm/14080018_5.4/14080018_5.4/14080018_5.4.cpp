// 14080018_5.4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;
typedef struct _NODE
{
	int value;
	struct _NODE *left;
	struct _NODE *right;

	_NODE(int value) : value(value), left(NULL), right(NULL) {};
}NODE, *PTRNODE;
void insert(PTRNODE &root, int value)
{
	if (root == NULL)
		root = new NODE(value);
	else
	{
		if (value < root->value)
			insert(root->left, value);
		else if (value > root->value)
			insert(root->right, value);
		else
			cout << "����ֵ��" << endl;
	}
}
void preOrder(PTRNODE root)
{
	if (root != NULL)
	{
		cout << root->value << "->";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(PTRNODE root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->value << "->";
		inOrder(root->right);
	}
}
void postOrder(PTRNODE root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		inOrder(root->right);
		cout << root->value << "->";
	}
}
void clear(PTRNODE &root)
{
	if (root != NULL)
	{
		clear(root->left);
		clear(root->right);

		delete root;
		root = NULL;
	}
}
void Search(PTRNODE root, int searchVal)
{
	if (root == NULL)
	{
		cout << "δ�ҵ��� " << endl;
		return;
	}

	if (searchVal < root->value)
		Search(root->left, searchVal);
	else if (searchVal > root->value)
		Search(root->right, searchVal);
	else
		cout << "�ҵ���" << endl;
}
int main(int argc, char *argv[])
{
	PTRNODE root = NULL;

	cout << "���ɵĽ��Ϊ�� " << endl;
	srand(time(0));
	for (int i = 0; i<10; i++)
	{
		int value = rand() % 100;
		cout << value << " ";

		insert(root, value);
	}

	cout << endl;

	cout << "ǰ�����: " << endl;
	preOrder(root);
	cout << endl;

	cout << "�������: " << endl;
	inOrder(root);
	cout << endl;

	cout << "ǰ�����: " << endl;
	postOrder(root);
	cout << endl;

	cout << "������ؼ���: ";
	int searchVal;
	cin >> searchVal;
	Search(root, searchVal);

	clear(root);

	return 0;
}