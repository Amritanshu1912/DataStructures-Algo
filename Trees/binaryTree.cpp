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
	~tree();

	node *getR() { return root; }
	void create();
	void preorder(node *);
	void inorder(node *);
	void postorder(node *);
	void levelorder(node *);
	int height(node *);
	int count(node *p);
	int countdeg2(node *p);
	int leafnode(node *p);
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
void tree::preorder(node *p)
{
	if (p)
	{
		cout << p->data << " ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void tree::inorder(node *p)
{
	if (p)
	{
		inorder(p->lchild);
		cout << p->data << " ";
		inorder(p->rchild);
	}
}
void tree::postorder(node *p)
{
	if (p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout << p->data << " ";
	}
}
void tree::levelorder(node *p)
{
	que ql;
	p = root;
	cout << p->data << "  " << endl;
	ql.enq(p);

	while (!ql.isEmpty())
	{
		p = ql.deq();
		if (p->lchild)
		{
			cout << p->lchild->data << "  ";
			ql.enq(p->lchild);
		}
		if (p->rchild)
		{
			cout << p->rchild->data << "  ";
			ql.enq(p->rchild);
		}
		cout << endl;
	}
}
int tree::height(node *p)
{
	if (p == NULL)
		return -1;

	if (height(p->lchild) > height(p->rchild))
		return height(p->lchild) + 1;
	else
		return height(p->rchild) + 1;
}
int tree::count(node *p)
{
	if (p == NULL)
		return 0;
	return count(p->lchild) + count(p->rchild) + 1;
}
int tree::countdeg2(node *p)
{
	if (p == NULL)
		return 0;

	if (p->lchild != NULL && p->rchild != NULL)
		return countdeg2(p->lchild) + countdeg2(p->rchild) + 1;
	else
		return 0;
}
int tree::leafnode(node *p)
{
	if (p == NULL)
		return 0;

	if (p->lchild == NULL && p->rchild == NULL)
		return 1;
	else
		return leafnode(p->lchild) + leafnode(p->rchild);
}

int main()
{

	tree t1;
	t1.create();

	t1.preorder(t1.getR());
	cout << endl;

	t1.inorder(t1.getR());
	cout << endl;

	t1.postorder(t1.getR());
	cout << endl;

	t1.levelorder(t1.getR());
	// cout << endl;

	// cout << "height of tree is : " << t1.height(t1.getR());
	// cout << endl;

	// cout << "total no. of nodes are : " << t1.count(t1.getR());
	// cout << endl;

	// cout << "no. of nodes with degree2 are : " << t1.countdeg2(t1.getR());
	// cout << endl;

	// cout << "no. of leaf node : " << t1.leafnode(t1.getR());
	// cout << endl;

	return 0;
}