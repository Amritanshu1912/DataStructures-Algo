#ifndef QandStak_for_graph_h
#define QandStak_for_graph_h

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node *next;
	node()
	{
		next = NULL;
	}
	node(int x)
	{
		data = x;
		next = NULL;
	}
};

class que
{
private:
	node *front = NULL;
	node *rear = NULL;

public:
	que()
	{
		front = NULL;
		rear = NULL;
	}
	void enq(int);
	int deq();
	int isEmpty();
	~que()
	{
		node *p = front;
		while (front)
		{
			front = front->next;
			delete p;
			p = front;
		}
	}
};
void que::enq(int x)
{
	node *t = new node(x);
	node *p = front;
	if (front == NULL)
	{
		front = t;
		rear = t;
	}
	else
	{
		rear->next = t;
		rear = t;
	}
}
int que::deq()
{
	if (isEmpty())
	{
		cout << "que is Empty" << endl;
		return -1;
	}
	int x;
	node *p = front;
	if (front->next != NULL)
		front = front->next;

	x = p->data;
	delete p;

	return x;
}
int que::isEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

class stak
{
private:
	node *top = NULL;

public:
	stak() { this->top = NULL; };
	~stak();
	void push(int);
	int pop();
	int getTop();
	int issEmpty();
};
stak::~stak()
{
	node *p = top;
	while (top)
	{
		top = top->next;
		delete p;
		p = top;
	}
}

void stak::push(int x)
{
	//cout<<"Pushing element : "<<x<<endl;
	node *t = new node(x);
	t->next = top;
	top = t;
}
int stak::pop()
{
	int x = -1;
	if (top == NULL)
		return x;
	else
	{
		node *p = top;
		top = top->next;
		x = p->data;
		delete p;
		return x;
	}
}
int stak::getTop()
{
	if (top)
		return top->data;

	else
	{
		return -1;
	}
}
int stak::issEmpty()
{
	return top ? 0 : 1;
}

#endif