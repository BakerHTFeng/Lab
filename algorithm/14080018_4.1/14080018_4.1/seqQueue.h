#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
#include "queue.h"
template <class T>
class SeqQueue :public Queue<T>             //ѭ�����е��ඨ��
{
protected:
	int rear, front;                    //��ͷ�Ͷ�βָ��
	T *elements;                        //��Ŷ���Ԫ�ص�����
	int maxSize;                        //������������Ԫ�ظ���
public:
	SeqQueue(int sz = 10);              //���캯��
	~SeqQueue() { delete[] elements; }   //��������
	bool EnQueue(const T& x);            //�����в�������x���ӣ�������������
	bool DeQueue(T& x);                  //�����в��գ����˳���ͷԪ��x���ɺ�������true������ӿգ�����false
	bool getFront(T& x);                 //�����в�Ϊ�գ���������true����ͷԪ�ص�ֵ�����򷵻�false
	void makeEmpty() { front = rear = 0; }   //�ÿղ�������ͷָ��Ͷ�βָ����0
	bool IsEmpty()const
	{
		return (front == rear) ? true : false;   //�ж��пշ������пգ���������true�����򷵻�false
	}
	bool IsFull() const
	{
		return ((rear + 1) % maxSize == front) ? true : false;   //�ж�������������������������true�����򷵻�false 
	}
	int getSize()const
	{
		return (rear - front + maxSize) % maxSize;          //�����Ԫ�ظ���
	}
	friend ostream& operator<<(ostream& os, SeqQueue<T>& Q);             //���������Ԫ�ص����ز���<<
};

template <class T>
SeqQueue<T>::SeqQueue(int sz) :front(0), rear(0), maxSize(sz)       //����һ��������maxSize��Ԫ�صĿն���
{
	elements = new T[maxSize];                               //�������пռ�
	assert(elements != NULL);                                //���ԣ���̬�洢����ɹ����
};

template <class T>
bool SeqQueue<T>::EnQueue(const T& x)        //�����в�������Ԫ��x���뵽�ö��еĶ�β�����������
{
	if (IsFull() == true) return false;            //�����������ʧ�ܣ�����
	elements[rear] = x;                            //���ն�βָ��ָʾλ�ò���
	rear = (rear + 1) % maxSize;                   //��βָ���1
	return true;                                   //����ɹ�������
};

template <class T>
bool SeqQueue<T>::DeQueue(T& x)            //�����в��������˵�һ����ͷԪ�ز�����true������������false
{
	if (IsEmpty() == true) return false;            //�����п���ɾ��ʧ�ܣ�����
	x = elements[front];                            
	front = (front + 1) % maxSize;                  //��ͷָ���1
	return true;                                    //ɾ���ɹ�������
};

template <class T>
bool SeqQueue<T>::getFront(T& x)                //�����в����������ظö��ж�ͷԪ�ص�ֵ
{
	if (IsEmpty() == true) return false;              //�����п��������ؿ�ָ��
	x = elements[front];                              //���ض�ͷԪ�ص�ֵ
	return true;
};

template<class T>
ostream& operator<<(ostream& os, SeqQueue<T>& Q)           //���������Ԫ�ص����ز���<<
{
	os << "front=" << Q.front << ",rear=" << Q.rear << endl;
	for (int i = front; i != rear; i = (i + 1) % maxSize)
		os << i << ":" << Q.elements[i] << endl;
	return os;
};