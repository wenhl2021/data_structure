#include<iostream>
using namespace std;

const int Stacksize = 100;

class SeqStack {  //链栈
public:
	SeqStack() { top = -1; }
	~SeqStack() { }
	void Push(int x);
	void Pop();
private:
	int data[Stacksize];
	int top;
};

void SeqStack::Push(int x) {
	if (top == Stacksize - 1) {
		cout << "上溢" << endl;
	}
	top = -1;
	int b = 2;
	int c = 0;
	while (x != 0) {

		c = x % b;
		data[++top] = c;
		x = x / b;
	}
}

void SeqStack::Pop() {
	int x = 0;
	if (top == -1) {
		cout << "下溢" << endl;
	}
	while (top != -1) {
		x = data[top--];
		cout << x;
	}
}

template <class DataType>
struct Node
{
	DataType data;
	Node<DataType>* next;
};

template <class DataType>
class CirLinkQueue  //循环链表队列
{
	Node* rear;
public:
	CirLinkQueue() { rear = NULL; }//构造函数
	void EnQueue(DataType x);//将元素x入队
	DataType DeQueue();//出队
};

template <class DataType>
void CirLinkQueue<DataType>::EnQueue(DataType x)
{
	Node* s = new Node;
	s->data = x;
	if (!rear)
	{
		rear = s;
		rear->next = rear;
	}
	else
	{
		s->next = rear->next;
		rear->next = s;
		rear = s;
	}
}

template <class DataType>
DataType CirLinkQueue<DataType>::DeQueue()
{
	if (!rear) throw”队空”;
	Node* p = rear->next;
	DataType x = p->data;
	if (rear->next == rear) rear = NULL;
	else rear->next = p->next;
	delete p;
	return x;
}