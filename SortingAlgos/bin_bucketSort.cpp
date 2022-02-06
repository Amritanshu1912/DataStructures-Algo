#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class node
{
public:
	int data;
	node *next;
};

void Display(int A[], int size)
{
	cout << endl;
	cout << "Sorted Array :	";
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int findmax(int A[], int size)
{
	int max = -1;
	int i = 0;
	while (i < size)
	{
		if (max < A[i])
			max = A[i];
		i++;
	}
	return max;
}

void Insert(node *&pos, int element)
{
	node *t = new node;
	t->data = element;
	t->next = NULL;

	if (pos == NULL)
	{
		pos = t;
	}
	else
	{
		node *p = pos;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = t;
	}
}
int Del(node *&head)
{
	node *q = head;

	if (head->next != NULL)
		head = head->next;
	else
		head = NULL;

	int n = q->data;
	delete q;
	return n;
}

int main()
{
	int A[] = {1, 1, 13, 19, 10, 14, 12, 7, 4, 2, 2, 5, 16, 8, 3, 3};
	int size = sizeof(A) / sizeof(A[0]);

	node **bin;
	int max = findmax(A, size);

	bin = new node *[max + 1];
	for (int i = 0; i < max + 1; i++)
	{
		bin[i] = NULL;
	}

	for (int i = 0; i < size; i++)
	{
		Insert(bin[A[i]], A[i]);
	}

	int i = 0, j = 0;
	while (i < max + 1)
	{
		while (bin[i] != NULL)
		{
			A[j++] = Del(bin[i]);
		}
		i++;
	}

	Display(A, size);

	return 0;
}