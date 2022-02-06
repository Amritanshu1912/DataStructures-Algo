#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
/* 
open hashing
	 - chaining
Closed Hashing
	 -Linear Probing
	 -Quad Probing 
	 -Double Hashing
*/
class node
{
public:
	int data;
	node *next;
	node() { next = NULL; }
	node(int x) { data = x, next = NULL; }
};
void insert(int x, node *&head)
{
	node *t = new node(x);
	if (head == NULL)
		head = t;
	else
	{
		node *p = head;
		node *q = NULL;
		while (p != NULL && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (x <= head->data)
		{
			t->next = head;
			head = t;
		}
		else
		{
			if (p != NULL)
			{
				t->next = p;
			}
			q->next = t;
		}
	}
}
void display(node **hash)
{

	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		node *p = hash[i];
		if (p == NULL)
			cout << "----" << endl;
		else
		{
			while (p != NULL)
			{
				cout << p->data << " -> ";
				p = p->next;
			}
			cout << endl;
		}
	}
	cout << endl;
}
void search(int key, node **hash)
{
	int n = key % 10;
	node *p = hash[n];

	while (p->data < key)
	{
		p = p->next;
	}
	if (p->data == key)
		cout << "key found : " << p->data;
	else
		cout << "not found" << endl;
	cout << endl;
}
int main()
{
	int A[] = {187, 117, 25, 31, 126, 156, 89, 36, 17, 34, 82, 189, 83, 116, 67};
	node **hash = new node *[10];
	for (int i = 0; i < 10; i++)
		hash[i] = NULL;

	int size = sizeof(A) / sizeof(A[0]);

	for (int i = 0; i < size; i++)
	{
		int num = A[i] % 10;
		insert(A[i], hash[num]);
	}

	display(hash);
	int key = 26;
	search(key, hash);

	return 0;
}