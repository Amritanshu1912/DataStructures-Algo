#include <iostream>
using namespace std;
typedef struct AVL
{
	struct AVL *lchild;
	int data;
	int height;
	struct AVL *rchild;
} AVL;
AVL *root = NULL;
int Count(AVL *p)
{
	if (p)
		return Count(p->lchild) + Count(p->rchild) + 1;
	return 0;
}
int Height(AVL *p)
{
	int x, y;
	if (!p)
		return 0;
	x = Height(p->lchild);
	y = Height(p->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}
AVL *InPre(AVL *p)
{
	while (p && p->rchild)
		p = p->rchild;
	return p;
}
AVL *InSuc(AVL *p)
{
	while (p && p->lchild)
		p = p->lchild;
	return p;
}
int NodeHeight(AVL *p)
{
	int hl, hr;
	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;
	return hl > hr ? hl + 1 : hr + 1;
}
int BalanceFactor(AVL *p)
{
	int hl, hr;
	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;
	return hl - hr;
}
AVL *LLRotation(AVL *p)
{
	AVL *pl, *plr;
	pl = p->lchild;
	plr = pl->rchild;

	pl->rchild = p;
	p->lchild = plr;
	//Height of 2 nodes gets changed i.e. p,pl
	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);
	if (root == p)
		root = pl;
	return pl;
}
AVL *LRRotation(AVL *p)
{
	AVL *pl, *plr;
	pl = p->lchild;
	plr = pl->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;
	plr->lchild = pl;
	plr->rchild = p;
	//Height of 3 nodes gets changed i.e. p,pl,plr
	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);
	plr->height = NodeHeight(plr);

	if (root == p)
		root = plr;
	return plr;
}
AVL *RRRotation(AVL *p)
{
	AVL *pr, *prl;
	pr = p->rchild;
	prl = pr->lchild;

	pr->lchild = p;
	p->rchild = prl;
	//Height of 2 gets changed i.e. p,pr
	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if (root == p)
		root = pr;
	return pr;
}
AVL *RLRotation(AVL *p)
{
	AVL *pr, *prl;
	pr = p->rchild;
	prl = pr->lchild;

	pr->lchild = prl->rchild;
	p->rchild = prl->lchild;
	prl->lchild = p;
	prl->rchild = pr;
	//Height of 3 Nodes gets changed i.e. p,pr,prl
	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);
	prl->height = NodeHeight(prl);

	if (root == p)
		root = prl;
	return prl;
}
//For Inserting in AVL Tree
AVL *insert(AVL *p, int key)
{
	AVL *t = NULL;
	if (p == NULL)
	{
		t = new AVL;
		t->data = key;
		t->height = 1;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data)
		p->lchild = insert(p->lchild, key);
	else if (key > p->data)
		p->rchild = insert(p->rchild, key);
	p->height = NodeHeight(p);
	//The above code is same as in insertion in BST
	//Tree balancing starts here
	if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
		return LLRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
		return LRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
		return RRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
		return RLRotation(p);
	return p;
}
//For Searching in an AVL Tree
bool Search(AVL *p, int key)
{
	if (p == 0)
		return false;
	bool ans = true;
	if (key == p->data)
		ans = true;
	else if (key < p->data)
		ans = Search(p->lchild, key);
	else
		ans = Search(p->rchild, key);
	return ans;
}
AVL *Delete(AVL *p, int key)
{
	if (p == NULL)
		return NULL;
	if (p->lchild == NULL && p->rchild == NULL)
	{
		if (p == root)
			root = NULL;
		delete p;
		return NULL;
	}
	if (key < p->data)
		p->lchild = Delete(p->lchild, key);
	else if (key > p->data)
		p->rchild = Delete(p->rchild, key);
	else if (key == p->data)
	{
		AVL *q;
		if (Height(p->lchild) > Height(p->rchild))
		{
			q = InPre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else
		{
			q = InSuc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}
	//The above code is same as in Deletion in BST
	//Now we will check if tree has become unbalanced we will check its balanced
	//factor and perform suitable AVL Tree rotations
	p->height = NodeHeight(p);
	if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
		return LLRotation(p); //L 1 Rotation
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
		return LRRotation(p); //L-1 Rotation
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
		return LLRotation(p); //L 0 Rotation
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == 1)
		return RRRotation(p); //R 1 Rotation
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == -1)
		return RLRotation(p); //R-1 Rotation
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == 0)
		return RRRotation(p); //R 0 Rotation
	return p;
}
//Preorder Traversal
void Preorder(AVL *p)
{
	if (p)
	{
		cout << p->data << " ";
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}
//Inorder Traversal
void Inorder(AVL *p)
{
	if (p)
	{
		Inorder(p->lchild);
		cout << p->data << " ";
		Inorder(p->rchild);
	}
}
//Postorder Traversal
void Postorder(AVL *p)
{
	if (p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		cout << p->data << " ";
	}
}
//This will Delete the entire AVL Tree
void DeleteAVL(AVL *p)
{
	if (p == NULL)
		return;
	DeleteAVL(p->lchild);
	DeleteAVL(p->rchild);
	delete p;
}
void MENU()
{
	printf("\n\n------MENU------\n");
	printf("1. Insert in AVL\n");
	printf("2. Search in AVL\n");
	printf("3. Delete from AVL\n");
	printf("4. Preorder - Display AVL\n");
	printf("5. Inorder - Display AVL\n");
	printf("6. Postorder - Display AVL\n");
	printf("7. Levelorder - Display AVL (select any other)\n");
	printf("8. Total Nodes in AVL\n");
	printf("9. Height of AVL\n");
	printf("10. Exit\n");
	printf("Enter your Choice : ");
}
int main()
{
	int n;
	cout << "Enter Total Nodes : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (i == 0)
			root = insert(root, x);
		else
			insert(root, x);
	}
	while (1)
	{
		int choice;
		MENU();
		cin >> choice;
		cout << "---------------\n\n";
		switch (choice)
		{
		case 1:
		{
			cout << "Enter Data : ";
			cin >> n;
			if (root == NULL)
				root = insert(root, n);
			else
				insert(root, n);
			break;
		}
		case 2:
		{
			cout << "Enter Data : ";
			cin >> n;
			if (Search(root, n))
				cout << "\nFound\n";
			else
				cout << "\nNot Found\n";
			break;
		}
		case 3:
		{
			cout << "Enter Value to be Deleted : ";
			cin >> n;
			Delete(root, n);
			cout << "Successfully Deleted" << endl;
			break;
		}
		case 4:
			cout << "Preorder : ";
			Preorder(root);
			break;
		case 5:
			cout << "Inorder : ";
			Inorder(root);
			break;
		case 6:
			cout << "Postorder : ";
			Postorder(root);
			break;
		case 7:
			cout << "LevelOrder : ";
			//LevelOrder(root);
			break;
		case 8:
			cout << "TotalNodes in BST = " << Count(root);
			break;
		case 9:
			cout << "Height of BST = " << Height(root);
			break;
		case 10:
			DeleteAVL(root);
			cout << "\nProgram Terminated\n";
			exit(0);
		default:
			cout << "\nWrong Choice\n";
		}
	}
	return 0;
}
