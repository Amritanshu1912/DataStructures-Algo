
#ifndef queAndstak_h
#define queAndstak_h

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class node
{
public:
	node *lchild;
	int data;
	node *rchild;
};

class qnode
{
public:
	node *data;
	qnode *next;
};

class que
{
private:
	qnode *front = NULL;
	qnode *rear = NULL;

public:
	que()
	{
		front = NULL;
		rear = NULL;
	}
	void enq(node *);
	node *deq();
	int isEmpty();
};

void que::enq(node *n)
{
	qnode *t = new qnode;
	t->data = n;
	t->next = NULL;
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
node *que::deq()
{
	node *x;
	qnode *p;
	if (isEmpty())
	{
		cout << "que is Empty" << endl;
	}
	else
	{
		p = front;
		front = front->next;
		x = p->data;
		delete p;
	}
	return x;
}
int que::isEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

class snode
{
public:
	node *data;
	snode *next;
};

class stak
{
private:
	snode *top = NULL;

public:
	stak() { this->top = NULL; };
	~stak();
	void push(node *);
	node *pop();
	node *sgetTop();
	int issEmpty();
};
stak::~stak()
{
	snode *p = top;
	while (top)
	{
		top = top->next;
		delete p;
		p = top;
	}
}

void stak::push(node *x)
{
	//cout<<"Pushing element : "<<x<<endl;
	snode *t = new snode;
	t->data = x;
	t->next = top;
	top = t;
}
node *stak::pop()
{
	node *x = NULL;
	if (top == NULL)
	{
		node *x1 = new node;
		x1->data = -1;
		return x1;
	}
	else
	{
		snode *p = top;
		top = top->next;
		x = p->data;
		delete p;
	}
	return x;
}
node *stak::sgetTop()
{
	if (top)
		return top->data;

	else
	{
		node *t = new node;
		t->data = -1;
		return t;
	}
}
int stak::issEmpty()
{
	return top ? 0 : 1;
}

#endif