#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class node
{
public:
	int data;
	int clr; //	black--> 0 | red--> 1
	node *lchild;
	node *rchild;
	node *parent;

	node(int x)
	{
		data = x;
		lchild = rchild = NULL;
		parent = NULL;
		clr = 1;
	}
};
class tree
{
private:
	node *root;

public:
	tree() { root = NULL; }
	tree(int);
	~tree();
	node *getR() { return root; }
	void setR(node *p)
	{
		this->root = p;
		this->root->parent = NULL;
	}

	void Destroy(node *);
	void preorder1(node *);
	void RInsert(int);
	bool redConflict(node *);
	void solveRedConflict(node *);
	void rightRotate(node *);
	void leftRotate(node *);
};
tree::tree(int x)
{
	root->data = x;
	root->clr = 0;
}
tree::~tree()
{
	Destroy(root);
}
void tree::Destroy(node *p)
{
	if (p)
	{
		Destroy(p->lchild);
		Destroy(p->rchild);
		delete p;
	}
}
void tree::preorder1(node *p)
{
	if (p != NULL)
	{
		if (p->lchild == NULL && p->rchild == NULL)
			cout << "{...<--" << p->data << "-->...}" << endl;
		else if (p->lchild == NULL)
			cout << "{...<--" << p->data << "--> " << p->rchild->data << " }" << endl;
		else if (p->rchild == NULL)
			cout << "{ " << p->lchild->data << " <--" << p->data << "-->...}" << endl;
		else
		{
			cout << "{ " << p->lchild->data << " <--" << p->data << "--> " << p->rchild->data << " }" << endl;
		}
		preorder1(p->lchild);
		preorder1(p->rchild);
	}
}

bool tree::redConflict(node *p)
{
	if (p->clr == 1 && p->parent->clr == 1)
		return 1;
	else
		return 0;
}
void tree::leftRotate(node *x)
{
	node *y = x->rchild;
	x->rchild = y->lchild;
	if (y->lchild != NULL)
	{
		y->lchild->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr)
	{
		this->root = y;
	}
	else if (x == x->parent->lchild)
	{
		x->parent->lchild = y;
	}
	else
	{
		x->parent->rchild = y;
	}
	y->lchild = x;
	x->parent = y;
}

void tree::rightRotate(node *x)
{
	node *y = x->lchild;
	x->lchild = y->rchild;
	if (y->rchild != NULL)
	{
		y->rchild->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr)
	{
		setR(y);
	}
	else if (x == x->parent->rchild)
	{
		x->parent->rchild = y;
	}
	else
	{
		x->parent->lchild = y;
	}
	y->rchild = x;
	x->parent = y;
}

void tree::solveRedConflict(node *k)
{
	node *u;
	while (k->parent->clr == 1)
	{
		if (k->parent == k->parent->parent->rchild)
		{
			u = k->parent->parent->lchild;
			if (u != NULL && u->clr == 1)
			{
				u->clr = 0;
				k->parent->clr = 0;
				k->parent->parent->clr = 1;
				k = k->parent->parent;
			}
			else
			{
				if (k == k->parent->lchild)
				{
					k = k->parent;
					rightRotate(k);
				}
				k->parent->clr = 0;
				k->parent->parent->clr = 1;
				leftRotate(k->parent->parent);
			}
		}
		else
		{
			u = k->parent->parent->rchild;

			if (u != NULL && u->clr == 1)
			{
				u->clr = 0;
				k->parent->clr = 0;
				k->parent->parent->clr = 1;
				k = k->parent->parent;
			}
			else
			{
				if (k == k->parent->rchild)
				{
					k = k->parent;
					leftRotate(k);
				}
				k->parent->clr = 0;
				k->parent->parent->clr = 1;
				rightRotate(k->parent->parent);
			}
		}
		if (k == root)
		{
			break;
		}
	}
	root->clr = 0;
}

void tree::RInsert(int key)
{
	node *q = NULL;
	node *p = root;

	while (p != NULL)
	{
		q = p;
		if (key < p->data)
			p = p->lchild;

		else if (key > p->data)
			p = p->rchild;
	}

	p = new node(key);
	p->parent = q;
	if (getR() == NULL)
	{
		p->clr = 0;
		p->parent = NULL;
		setR(p);
	}
	if (q != NULL)
	{
		if (p->data < q->data)
			q->lchild = p;
		else
			q->rchild = p;
	}

	if (p->parent == NULL || p->parent->parent == NULL)
	{
		return;
	}

	if (redConflict(p))
	{
		solveRedConflict(p);
	}
}

int main()
{
	tree t;
	t.RInsert(10);
	t.RInsert(20);
	t.RInsert(30);
	t.RInsert(40);
	t.RInsert(25);
	t.RInsert(50);
	t.RInsert(60);
	t.RInsert(70);
	t.preorder1(t.getR());
	return 0;
}