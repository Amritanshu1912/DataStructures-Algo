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

class tree
{
private:
	node *root;

public:
	tree() { root = NULL; }
	tree(int);
	~tree();

	node *getR() { return root; }
	void setR(node *root) { this->root = root; }
	void preorder(node *);
	void preorder1(node *);
	void inorder(node *);
	void postorder(node *);
	int height(node *);
	node *inpre(node *);
	node *insuc(node *);
	void Insert(int);
	node *RecInsert(node *, int);
	node *loopSearch(node *, int);
	node *RecSearch(node *, int);
	node *Delete(node *, int);
	void DestroyRecursive(node *);
};
tree::tree(int x)
{
	root = new node;
	root->data = x;
	root->lchild = root->rchild = NULL;
}
tree::~tree()
{
	DestroyRecursive(getR());
}
void tree::DestroyRecursive(node *p)
{
	if (p)
	{
		DestroyRecursive(p->lchild);
		DestroyRecursive(p->rchild);
		delete p;
	}
}

node *tree::inpre(node *p)
{
	while (p->rchild != NULL)
	{
		p = p->rchild;
	}
	return p;
}
node *tree::insuc(node *p)
{
	while (p->lchild != NULL)
	{
		p = p->lchild;
	}
	return p;
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
int tree::height(node *p)
{
	if (p == NULL)
		return -1;

	if (height(p->lchild) > height(p->rchild))
		return height(p->lchild) + 1;
	else
		return height(p->rchild) + 1;
}
node *tree::loopSearch(node *p, int key)
{
	while (p != NULL)
	{
		if (p->data == key)
			return p;
		else if (key < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return NULL;
}
node *tree::RecSearch(node *p, int key)
{
	if (p == NULL)
		return NULL;
	if (p->data == key)
		return p;
	else if (key < p->data)
		RecSearch(p->lchild, key);
	else
		RecSearch(p->rchild, key);

	//return NULL;
}
void tree::Insert(int key)
{
	node *p = root;
	node *r = NULL;
	while (p != NULL)
	{
		r = p;
		if (key == p->data)
			return;
		else if (key < p->data)
		{
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
	}
	p = new node;
	p->data = key;
	p->lchild = p->rchild = NULL;
	if (p->data < r->data)
		r->lchild = p;
	else
		r->rchild = p;
}
node *tree::RecInsert(node *p, int key)
{
	node *t;
	if (p == NULL)
	{
		t = new node;
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data)
		p->lchild = RecInsert(p->lchild, key);
	else
		p->rchild = RecInsert(p->rchild, key);
	return p;
}
node *tree::Delete(node *p, int key)
{
	if (p == NULL)
		return NULL;

	if (p->lchild == NULL && p->rchild == NULL)
	{
		if (p == root)
			setR(NULL);
		delete p;
		return NULL;
	}
	if (key < p->data)
		p->lchild = Delete(p->lchild, key);
	else if (key > p->data)
		p->rchild = Delete(p->rchild, key);
	else
	{
		if (height(p->lchild) > height(p->rchild))
		{
			node *q = inpre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else
		{
			node *q = insuc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}
	return p;
}

int main()
{

	tree t1;
	t1.setR(t1.RecInsert(t1.getR(), 4));
	t1.RecInsert(t1.getR(), 2);
	t1.RecInsert(t1.getR(), 6);
	t1.RecInsert(t1.getR(), 1);
	t1.RecInsert(t1.getR(), 3);
	t1.RecInsert(t1.getR(), 5);
	t1.RecInsert(t1.getR(), 7);

	t1.inorder(t1.getR());
	cout << endl;
	cout << endl;
	t1.preorder1(t1.getR());

	t1.Delete(t1.getR(), 4);
	cout << endl;
	t1.preorder1(t1.getR());
	// t1.inorder(t1.getR());
	// cout << endl;

	return 0;
}