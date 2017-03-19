// 14080018_5.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
#define MAXSIZE 200  
struct SeqList                              
{      
	int digit[MAXSIZE];     
	int length; 
};
int Search(SeqList &List, int low, int high, int key); 
void main()                                         
{      
	int i, j, key, low, high; 
	SeqList List;
	cout << "���������ָ���:";
	cin >> j;
	printf("����������(����):\n"); 
	for (i = 0; i < j; i++)
	{         
		cin >> List.digit[i];
	}      
	List.length = j; 
	low = 0; 
	high = List.length - 1; 
	printf("������ؼ���:\n"); 
	cin >> key;
	i =  Search(List, low, high, key);
	if (i != -1)
		cout << "�ҵ����ǵ�" << i + 1 << "��Ԫ��";
	else printf("δ�ҵ���\n"); 
}   

int Search(SeqList &List,int low,int high,int key)      
{      
	int k = -1;
	if (low <= high)
	{          
		int mid; 
		mid = (low + high) / 2; 
		if (List.digit[mid] == key)
		{
			cout << List.digit[mid] << "=" << key << endl;
			k = mid;
		}
		else if (List.digit[mid] < key)
		{
			cout << List.digit[mid] << "<" << key << endl;
			k = Search(List, mid + 1, high, key);
		}
		else
		{
			cout << List.digit[mid] << ">" << key << endl;
			k = Search(List, low, mid - 1, key);
		}
	}      
	return k; 
}