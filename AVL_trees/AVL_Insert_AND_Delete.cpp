#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class node
{
public:
	int data;
	int height;
	node *lchild;
	node *rchild;

	node() { lchild = rchild = NULL; }
	node(int x)
	{
		this->data = x;
		lchild = rchild = NULL;
	}
};
class tree
{
private:
	node *root;

public:
	tree() { root = NULL; }
	tree(int x) { root = new node(x); }
	~tree();
	node *getR() { return root; }
	void setR(node *root) { this->root = root; }

	void preorder1(node *);
	void inorder(node *);
	node *inpre(node *);
	node *insuc(node *);
	node *Insert(node *, int);
	node *RecSearch(node *, int);
	node *Delete(node *, int);
	int NodeHeight(node *);
	int BalFactor(node *p);
	node *LLRotation(node *p);
	node *RRRotation(node *p);
	node *RLRotation(node *p);
	node *LRRotation(node *p);
	void DestroyRecursive(node *);
};

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
		p = p->rchild;
	return p;
}
node *tree::insuc(node *p)
{
	while (p->lchild != NULL)
		p = p->lchild;
	return p;
}
int tree::NodeHeight(node *p)
{
	int hl, hr;
	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;

	return hl > hr ? hl + 1 : hr + 1;
}
int tree::BalFactor(node *p)
{
	int hl, hr;
	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;

	return hl - hr;
}
node *tree::LLRotation(node *p)
{
	node *pl = p->lchild;

	p->lchild = pl->rchild;
	pl->rchild = p;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	if (root == p)
		setR(pl);
	return pl;
}
node *tree::RRRotation(node *p)
{
	node *pr = p->rchild;

	p->rchild = pr->lchild;
	pr->lchild = p;
	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if (root == p)
		setR(pr);
	return pr;
}
node *tree::RLRotation(node *p)
{
	node *pr = p->rchild;
	node *prl = pr->lchild;

	p->rchild = prl->lchild;
	pr->lchild = prl->rchild;
	prl->lchild = p;
	prl->rchild = pr;

	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);
	prl->height = NodeHeight(prl);

	if (root == p)
		setR(prl);
	return prl;
}
node *tree::LRRotation(node *p)
{
	node *pl = p->lchild;
	node *plr = pl->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;

	plr->lchild = pl;
	plr->rchild = p;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);
	plr->height = NodeHeight(plr);

	if (root == p)
		setR(plr);
	return plr;
}
node *tree::Insert(node *p, int key)
{
	if (p == NULL)
	{
		node *t = new node(key);
		t->height = 1;
		if (p == root)
			setR(t);
		return t;
	}
	if (key < p->data)
		p->lchild = Insert(p->lchild, key);
	else if (key > p->data)
		p->rchild = Insert(p->rchild, key);

	p->height = NodeHeight(p);

	if (BalFactor(p) == 2 && BalFactor(p->lchild) == 1)
		return LLRotation(p);
	else if (BalFactor(p) == -2 && BalFactor(p->rchild) == -1)
		return RRRotation(p);
	else if (BalFactor(p) == 2 && BalFactor(p->lchild) == -1)
		return LRRotation(p);
	else if (BalFactor(p) == -2 && BalFactor(p->rchild) == 1)
		return RLRotation(p);

	return p;
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
node *tree::Delete(node *p, int key)
{
	if (p == NULL)
	{
		return NULL;
	}
	if (p->lchild == NULL && p->rchild == NULL)
	{
		if (p == root)
			setR(NULL);
		delete p;
		return NULL;
	}
	if (key < p->data)
	{
		p->lchild = Delete(p->lchild, key);
	}
	else if (key > p->data)
	{
		p->rchild = Delete(p->rchild, key);
	}
	else
	{
		if (NodeHeight(p->lchild) > NodeHeight(p->rchild))
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
	p->height = NodeHeight(p);
	if (BalFactor(p) == 2 && BalFactor(p->lchild) == 1)
		return LLRotation(p);
	else if (BalFactor(p) == 2 && BalFactor(p->lchild) == -1)
		return LRRotation(p);
	else if (BalFactor(p) == 2 && BalFactor(p->lchild) == 0)
		return LRRotation(p);
	else if (BalFactor(p) == -2 && BalFactor(p->rchild) == -1)
		return RRRotation(p);
	else if (BalFactor(p) == -2 && BalFactor(p->rchild) == 1)
		return RLRotation(p);
	else if (BalFactor(p) == -2 && BalFactor(p->rchild) == 0)
		return RLRotation(p);
	return p;
}
int main()
{
	tree t;
	t.Insert(t.getR(), 50);
	for (int i = 1; i < 10; i++)
	{
		if (i == 5)
			continue;
		t.Insert(t.getR(), 10 * i);
	}

	t.preorder1(t.getR());
	cout << endl;

	t.Delete(t.getR(), 40);
	t.Delete(t.getR(), 70);

	t.preorder1(t.getR());

	return 0;
}