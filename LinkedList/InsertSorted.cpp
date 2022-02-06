#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node
{

public:
	int data;
	node *next; //self referential structure

	~node()
	{
	}

	void create(int);
	int del(int);
	void display(node *);
	void InsertSorted(int);
	int checkSorted();
	void removeDup();
	void reverseLL();

} *head = NULL;

void create(int x)
{

	node *temp = new node;
	temp->data = x;
	temp->next = NULL;

	node *last;
	if (head == NULL)
	{
		head = temp;
		last = temp;
	}
	else
	{
		// while(temp1->next != NULL){
		// temp1 = temp1->next;
		// }
		last->next = temp;
		last = temp;
	}
}

int del(int pos)
{
	int x;
	if (pos == 1)
	{
		node *p = head;
		head = head->next;
		x = p->data;
		delete p;
	}
	else if (pos != 1)
	{
		node *p = head;
		node *q = NULL;
		for (int i = 0; i < pos - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	return x;
}

void InsertSorted(int num)
{
	node *p = head;
	node *q = NULL;
	if (p == NULL)
	{
		node *t = new node;
		t->data = num;
		t->next = NULL;
		head = t;
	}
	else
	{
		node *t = new node;

		while (p && p->data < num)
		{
			q = p;
			p = p->next;
		}
		if (head->data >= num)
		{
			t->data = num;
			t->next = head;
			head = t;
		}
		else
		{
			t->data = num;
			t->next = q->next;
			q->next = t;
		}
	}
}
int checkSorted()
{

	int x = -32768;
	node *p = head;
	while (p != NULL)
	{
		if (p->data < x)
			return false;
		x = p->data;
		p = p->next;
	}
	return true;
}

void removeDup()
{

	node *p, *q;
	q = head->next;
	p = head;

	while (q != NULL)
	{
		if (q->data != p->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}
void reverseLL()
{
	node *p = head;
	node *q = NULL;
	node *r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}
void recReverse(node *q, node *p)
{
	if (p != NULL)
	{
		recReverse(p, p->next);
		p->next = q;
	}
	else
	{
		head = q;
	}
}

void display(node *n)
{

	if (n != 0)
	{
		cout << n->data << "  ";
		display(n->next);
	}
}

int main()
{
	cout << "enter elements :" << endl;

	for (int i = 0; i < 4; i++)
	{

		int x;
		cin >> x;
		create(x);
	}

	display(head);
	cout << endl;

	int choice;
	cout << "--------MENU--------" << endl;
	cout << "1. Insert" << endl;
	cout << "2. Display" << endl;
	cout << "3. Delete" << endl;
	cout << "4. Check if Sorted" << endl;
	cout << "5. Remove Duplicate" << endl;
	cout << "6. Reverse LL " << endl;
	cout << endl;

	cout << "Choose between 1-6 : ";
	cin >> choice;

	while (choice >= 1 && choice <= 6)
	{

		switch (choice)
		{
		case 1 /* Insert in a sorted LL*/:

			cout << "enter element to insert - ";
			int nu;
			cin >> nu;
			InsertSorted(nu);
			display(head);
			cout << endl;
			break;

		case 2 /* constant-expression */:
			display(head);
			cout << endl;
			break;

		case 3 /*delete from a pos*/:
			int pos;
			cout << "Enter a position to delte node from - ";
			cin >> pos;
			cout << "Deleted element is - " << del(pos) << endl;
			display(head);
			cout << endl;
			break;

		case 4 /*Check if LL is Sorted*/:
			int flag;
			flag = checkSorted();
			flag > 0 ? cout << "Sorted" << endl : cout << "not sorted" << endl;

			break;

		case 5 /*Remove Duplicate*/:

			removeDup();
			display(head);
			cout << endl;
			break;

		case 6 /*Reverse LL by reversing links*/:

			//reverseLL();
			recReverse(NULL, head);
			display(head);
			cout << endl;
			break;

		default:
			break;
		}

		cout << "Choose between 1-6 : ";
		cin >> choice;
	}
	cout << "Invalid input...aborting execution..." << endl;

	delete head;

	return 0;
}
