#include <iostream>
#include "Tree.h"

void main()
{
	Tree BinaryTree("A(B(D(G,),E(,H)),C(F(,I(J,K)),)");
	int n = 0;
	BinaryTree.NumOfNode(BinaryTree.GetRoot(),n);
	cout << "�����Ϊ" << n << endl;
	cout << "����������ݹ飩Ϊ";
	BinaryTree.In_Rec(BinaryTree.GetRoot());
	cout << "\n����������ǵݹ飩Ϊ";
	BinaryTree.In(BinaryTree.GetRoot());
	// ������
	cout << "\n�����������Ϊ";
	BinaryTree.InThread(BinaryTree.GetRoot());
	BinaryTree.In_Thread(BinaryTree.GetRoot());
}
