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

	void Preorder1(node *);
	node *getR() { return root; }
	void setR(node *root) { this->root = root; }
	void generateFromPre(int[], int);
	void generateFromPost(int[], int);
};
tree::tree(int rootval)
{
	this->root->data = rootval;
	this->root->lchild = this->root->rchild = NULL;
}
tree::~tree()
{
	static node *p = root;
	if (p)
	{
		if (p->lchild != NULL)
		{
			p = p->lchild;
			this->tree::~tree();
		}
		if (p->rchild != NULL)
		{
			p = p->rchild;
			this->tree::~tree();
		}

		delete p;
	}
}
void tree::Preorder1(node *p)
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
		Preorder1(p->lchild);
		Preorder1(p->rchild);
	}
}
void tree::generateFromPost(int post[], int n)
{
	stak st1;

	node *temp = new node;
	temp->data = post[n - 1];
	temp->lchild = temp->rchild = NULL;
	setR(temp);
	st1.push(temp);
	node *p = root;
	int i = n - 2;

	while (i >= 0)
	{
		if (post[i] > p->data)
		{
			node *t = new node;
			t->data = post[i--];
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			st1.push(p);
			p = t;
		}
		else
		{
			if (post[i] < p->data && post[i] > st1.sgetTop()->data)
			{
				node *t = new node;
				t->data = post[i--];
				t->lchild = t->rchild = NULL;
				p->lchild = t;
				p = t;
			}
			else
			{
				while (post[i] < st1.sgetTop()->data && !st1.issEmpty())
				{
					p = st1.pop();
				}
			}
		}
	}
}
void tree::generateFromPre(int Pre[], int n)
{
	stak st;
	node *t;
	int i = 0;
	node *temp = new node;
	temp->data = Pre[i++];
	temp->lchild = temp->rchild = NULL;
	setR(temp);

	node *p = root;
	while (i < n)
	{
		if (Pre[i] < p->data)
		{
			t = new node;
			t->data = Pre[i++];
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			st.push(p);
			p = t;
		}
		else
		{
			if (Pre[i] > p->data && Pre[i] < st.sgetTop()->data)
			{
				t = new node;
				t->data = Pre[i++];
				t->lchild = t->rchild = NULL;
				p->rchild = t;
				p = t;
			}
			else
			{
				p = st.pop();
			}
		}
	}
}
int main()
{
	int Pre[] = {1, 3, 4, 2, 7, 6, 9, 8, 5};
	tree t1;
	// t1.generateFromPre(Pre, 8);
	// t1.Preorder1(t1.getR());

	t1.generateFromPost(Pre, 9);
	t1.Preorder1(t1.getR());

	return 0;
}