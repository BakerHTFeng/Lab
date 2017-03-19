#pragma once
template <class  T>
// ��ʽջ
class LinkStack
{
private:
	// ��ʽջs�еĽ��ṹ
	struct LNode
	{
		T data; // ����
		struct LNode *next;// ָ��
	}*top;
	// ջ��/ջ��ָ��
public:
	// ��ʼ��
	LinkStack() { top = NULL; }
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
void LinkStack<T>::InitStack()
{
	if (this->StackEmpty())
		cout << "ջ��Ϊ�գ�\n";
	else
	{
		LNode *p;
		while (top)
		{
			p = top;
			top = top->next;
			free(p);
		}
		cout << "���óɹ���\n";
	}
}

template <class T>
bool LinkStack<T>::StackEmpty()
{
	return top == NULL ? true : false;
}

template <class T>
void LinkStack<T>::Push(T x)
{
	LNode *p;
	p = new LNode;
	if (!p)
	{
		cout << "�ڴ����ʧ��!" << endl;
		exit(1);
	}
	p->data = x;
	p->next = top;
	top = p;
	cout << "��ջԪ��Ϊ��" << x << endl;
}

template <class T>
void LinkStack<T>::Pop()
{
	if (this->StackEmpty())
		cout << "ջΪ��\n";
	else
	{
		LNode *p;
		p = top;
		cout << "��ջԪ��Ϊ��" << top->data << endl;
		top = top->next;
		free(p);
	}
}

template<class T>
void LinkStack<T> ::GetTop()
{
	if (this->StackEmpty())
		cout << "ջΪ��\n";
	else cout << "ջ��Ԫ��Ϊ��" << top->data << endl;
}