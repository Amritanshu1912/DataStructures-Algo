#include <bits/stdc++.h>
#include <iostream>
#include "queAndstak.h"

using namespace std;

class tree
{
private:
	node *root;

public:
	tree() { root = NULL; }
	tree(int);
	~tree();

	node *getR() { return root; }
	void create();
	void preorder();
	void inorder();
	void postorder();
};
tree::~tree()
{
	static node *p = root;
	if (p)
	{
		p = p->lchild;
		this->tree::~tree();
		p = p->rchild;
		this->tree::~tree();

		delete p;
	}
}

void tree::create()
{
	root = new node;
	int x = -1;
	que q;
	root->lchild = root->rchild = NULL;

	cout << "enter root node : ";
	cin >> x;

	root->data = x;
	q.enq(root);

	node *p, *t;
	while (!q.isEmpty())
	{
		p = q.deq();
		cout << "Enter left child of " << p->data << " : ";
		cin >> x;
		if (x != -1)
		{
			t = new node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enq(t);
		}
		cout << "Enter right child of " << p->data << " : ";
		cin >> x;
		if (x != -1)
		{
			t = new node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enq(t);
		}
	}
}
void tree::preorder()
{
	stak st1;
	node *t = root;
	while (t != NULL || !st1.issEmpty())
	{
		if (t != NULL)
		{
			cout << t->data << "  ";
			st1.push(t);
			t = t->lchild;
		}
		else
		{
			t = st1.pop();
			t = t->rchild;
		}
	}
}
void tree::inorder()
{
	stak st2;
	node *t = root;
	while (t != NULL || !st2.issEmpty())
	{
		if (t != NULL)
		{
			st2.push(t);
			t = t->lchild;
		}
		else
		{
			t = st2.pop();
			cout << t->data << "  ";
			t = t->rchild;
		}
	}
}
void tree::postorder()
{
	stak st3;
	long long int temp;
	node *t = root;
	while (t != NULL || !st3.issEmpty())
	{
		if (t != NULL)
		{
			st3.push(t);
			t = t->lchild;
		}
		else
		{
			temp = (long long int)st3.pop();
			if (temp > 0)
			{
				st3.push((node *)(-1 * temp));
				t = ((node *)temp)->rchild;
			}
			else
			{
				cout << ((node *)temp)->data << "  ";
				t = NULL;
			}
		}
	}
}

int main()
{

	tree t1;
	t1.create();

	t1.preorder();
	cout << endl;

	t1.inorder();
	cout << endl;

	t1.postorder();
	cout << endl;

	return 0;
}