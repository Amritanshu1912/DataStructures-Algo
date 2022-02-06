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
	int dig = 0;
	while (max--)
	{
		max = max / 10;
		dig++;
	}

	return dig;
}
int findbin(int num, int p)
{
	int numbin = (num / p) % 10;
	return numbin;
}
void insert(node *&p, int val)
{
	node *t = new node;
	t->data = val;
	t->next = NULL;

	if (p == NULL)
	{
		p = t;
	}
	else
	{
		node *q = p;
		while (q->next != NULL)
			q = q->next;
		q->next = t;
	}
}
int Del(node *&head)
{
	node *q = head;
	if (head->next != NULL)
	{
		head = head->next;
	}
	else
	{
		head = NULL;
	}
	int x = q->data;
	delete q;
	return x;
}
int main()
{
	int A[] = {239, 288, 46, 647, 741, 7708, 754, 5, 277};

	int size = sizeof(A) / sizeof(A[0]);

	int maxdig = findmax(A, size);

	node **bin = new node *[10];
	for (int i = 0; i < 10; i++)
	{
		bin[i] = NULL;
	}

	int i = 0;
	while (i < maxdig)
	{
		int j = 0;
		int p = pow(10, i);

		while (j < size)
		{
			int numbin = findbin(A[j], p);
			insert(bin[numbin], A[j]);
			j++;
		}
		j = 0;
		int k = 0;
		while (j < 10)
		{
			while (bin[j] != NULL)
			{
				A[k++] = Del(bin[j]);
			}
			j++;
		}
		i++;
	}

	Display(A, size);
	return 0;
}