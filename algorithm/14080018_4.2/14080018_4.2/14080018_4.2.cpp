// 14080018_4.2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
#include "Graph.h"



int main()
{
	Graph<char, int> G(20);
	G.Input();
	cout << "��СȨΪ:" << G.Prim() << endl;
    return 0;
}

