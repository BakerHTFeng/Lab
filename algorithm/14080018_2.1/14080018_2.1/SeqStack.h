#pragma once 
#define StackSize 5
typedef int T;
template <class  T>
// ˳��ջ
class SeqStack
{
	private:
		// ջ�ڴ洢����
		T data[StackSize];
		// ջ��ָ��
		int top;
	public:
		// ��ʼ��
		SeqStack() { top = -1; }
		// �ÿ�ջ
		void InitStack();
		// �ж��Ƿ�Ϊ��ջ
		bool StackEmpty();
		// ��ջ
		void Push(T x);
		// ��ջ
		void Pop();
		// ȡջ��Ԫ��
		void GetTop();
};

template <class T>
void SeqStack<T>::InitStack()
{
	if (this->StackEmpty())
		cout << "ջ��Ϊ�գ�\n";
	else
	{
		top = -1;
		cout << "���óɹ���\n" ;
	}
}

template <class T>
bool SeqStack<T>::StackEmpty()
{
	return top == -1 ? true : false;
}

template <class T>
void SeqStack<T>:: Push(T x)
{
	if (top == StackSize - 1) cout << "����" << endl;
	else
	{
		cout << "��ջԪ��Ϊ��" << x << endl;
		data[++top] = x;
	}
}

template <class T>
void SeqStack<T>::Pop() 
{
	if (this->StackEmpty()) cout << "����\n";
	else cout << "��ջԪ��Ϊ��" << data[top--] <<  endl;
}

template <class T>
void SeqStack<T>::GetTop()
{
	if (this->StackEmpty()) cout << "ջΪ��\n";
	else cout << data[top] << endl;
}
