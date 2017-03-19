#include "stdafx.h"
using namespace std;
typedef char TElemType;
typedef struct Node 
{
	TElemType data;
	struct Node *lchild, *rchild;
}BinaryTreeN, *BinaryTree;
int CreateBinaryTree(BinaryTree  &T) 
{
	//��ǰ��������򴴽�����������������
	//�������ڵĽ����*���棩����"AB*DG***CEM**N**F*X**"
	char ch;
	getchar();
	cout << "\n�������������Ԫ��\n";
	cin >> ch;
	if (ch == '*')
		T = NULL;
	else 
	{
		if (!(T = (BinaryTreeN *)malloc(sizeof(BinaryTreeN)))) 
			exit(-1);
		T->data = ch;
		CreateBinaryTree(T->lchild);
		CreateBinaryTree(T->rchild);
	}
	return 1;
}//����������
int PreOrderT(BinaryTree  T) 
{
	//ǰ����������� T����ӡÿ������������һ���ҽ�һ��
	if (T != NULL) 
	{
		cout << T->data << " \n";
		PreOrderT(T->lchild);
		PreOrderT(T->rchild);
	}
	return 1;
}//�������������
int InOrderT(BinaryTree  T) 
{
	//������������� T����ӡÿ������������һ���ҽ�һ��
	if (T != NULL) 
	{
		InOrderT(T->lchild);
		cout << T->data << " \n";
		InOrderT(T->rchild);
	}
	return 1;
}//������������� T

int PostOrderT(BinaryTree  T) {
	//������������� T����ӡÿ������������һ���ҽ�һ��
	if (T != NULL) {
		PostOrderT(T->lchild);
		PostOrderT(T->rchild);
		cout << T->data << " \n";
	}
	return 1;
}//������������� T

int BinaryTreenum(BinaryTree T, int& n) {
	// ��д�㷨ͳ�ƶ�����T(��������洢�ṹ)�Ľ������
	if (T != NULL) 
	{
		BinaryTreenum(T->lchild, n);
		n++;
		BinaryTreenum(T->rchild, n);
	}
	return n;
}

int main() {
	BinaryTree T = new Node;
	int j, n = 0;
	do
	{
		system("cls");
		cout << "\n��������Ҫ�Ĺ���\n";
		cout << "-----�����ķָ���------\n";
		cout << "1:��ǰ��������򴴽�������\n";
		cout << "2:ǰ����������� T\n";
		cout << "3:������������� T\n";
		cout << "4:������������� T\n";
		cout << "5:ͳ�ƶ�����T�Ľ������\n";
		cout << "0:�˳�����\n";
		cout << "-----�����ķָ���------\n";
		cin >> j;
		system("cls");
		switch (j) 
		{
			case 1:
				CreateBinaryTree(T); 
				system("pause");
				break;
			case 2:
				PreOrderT(T);
				system("pause");
				break;
			case 3:
				InOrderT(T); 
				system("pause");
				break;
			case 4:
				PostOrderT(T);
				system("pause");
				break;
			case 5:
				cout << BinaryTreenum(T, n) << endl;
				system("pause");
				break;
			case 0:
				exit(1);
		}
	} while (j);
	return 0;
}