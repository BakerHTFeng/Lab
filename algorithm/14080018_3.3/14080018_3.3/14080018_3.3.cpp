// 14080018_3.3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Huffman.h"
int main()
{
	Huffman Tree("CASTCASTSATATATASA");
	Tree.Code("", Tree.GetRoot());
	cout << "Huffman����Ϊ��";
	Tree.Decode("111011001110110011001001001001100");
	return 0;
}
