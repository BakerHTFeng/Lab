// 14080018_5.2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
template <class T>
struct LinkNode
{
	T data;
	LinkNode* next;
};

template<class T>
T Search(LinkNode<T>* Node, T key)
{
	LinkNode<T>*p;
	int n = 0;
	for (p = Node; p->next != NULL; p = p->next)
	{
		n++;
		if (p->data == key)
			return n;
	}
	return 0;
}

int main()
{	
	LinkNode<int> *Head, *p, *q;
	Head = new LinkNode<int>;
	Head->next = NULL;
	p = Head;
	int n, key;
	cout << "���������ָ�����";
	cin >> n;
	cout << "��ֱ��������֣����򣩣�";
	cin >> Head->data;
	for (int i = 2; i <= n;i++)
	{
		q = new LinkNode<int>;
		cin >> q->data;
		p->next = q;
		q->next = NULL;
		p = q;
	}
	cout << "������ؼ��ʣ�";
	cin >> key;
	if (Search(Head, key))
		cout << "�ҵ����ڵ�"<<Search(Head,key)<<"���ڵ㡣\n";
	else cout << "δ�ҵ���\n";
    return 0;
}

