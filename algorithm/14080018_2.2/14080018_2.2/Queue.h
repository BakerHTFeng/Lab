#pragma once
typedef int T;
template <class  T>
// ����
class Queue
{
private:
	// �����еĽ��ṹ
	struct LNode
	{
		T data; // ����
		struct LNode *next;// ָ��
	}*head,*rear;
	// βָ��
public:
	// ��ʼ��
	Queue() { rear = NULL; head = new LNode; head -> next = NULL; }
	// �ÿն���
	void InitQueue();
	// �ж��Ƿ�Ϊ�ն�
	bool QueueEmpty();
	// ����
	void In(T x);
	// ����
	void Out();
};

template <class T>
void Queue<T>::InitQueue()
{
	LNode *p;
	if (this->QueueEmpty())
		cout << "������Ϊ�գ�\n";
	else
	{
		while (rear->next != rear)
		{
			p = rear->next;
			rear->next = p->next;
			free(p);
		}
		free(rear);
		rear = NULL;
		head->next = rear;
		cout << "���óɹ���" << endl;
	}
}

template <class T>
bool Queue<T>::QueueEmpty()
{
	return head -> next == NULL ? true : false;
}

template <class T>
void Queue<T>::In(T x)
{
	LNode *p;
	p = new LNode;
	if (!p)
	{
		cout << "�ڴ����ʧ��!" << endl;
		exit(1);
	}
	p -> data = x;
	if(this -> QueueEmpty())
	{ 
		head -> next = p;
		rear = p;
		rear -> next = p;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;
		rear = p;
	}
	cout << "���Ԫ��Ϊ��" << x << endl;
}

template <class T>
void Queue<T>::Out()
{
	if (this->QueueEmpty())
		cout << "����Ϊ��\n";
	else
	{	
		LNode *p;

		p = rear -> next;
		cout << "����Ԫ��Ϊ��" << p -> data << endl;
		if (p == rear)
		{
			free(p); 
			rear = NULL;
			head->next = rear;
		}
		else
		{
			rear->next = p->next;
			free(p);
		}
		
	}
}