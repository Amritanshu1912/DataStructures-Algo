#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;
};
class heap
{
private:
	int A[16] = {0, 20, 30, 40, 50, 60, 70, 80};
	int last = 7;
	void insertFix(int);

public:
	int *getA() { return A; }
	int getL() { return last; }
	void createHeap(int);
	void heapify();
	void insert(int);
	void heapsort();
	void Delete();
	void print();
};
void heap::createHeap(int n)
{

	for (int i = 0; i < n; i++)
	{
		insertFix(2 + i);
	}
}
void heap::heapify()
{
	int i, j, temp;
	i = last;
	j = 2 * i;
	while (i > 0)
	{
		if (j < last)
		{
			int k = i;
			while ((j < last) && (A[k] < A[j] || A[k] < A[j + 1]))
			{
				if (A[j] < A[j + 1])
					j = j + 1;

				temp = A[j];
				A[j] = A[k];
				A[k] = temp;
				k = j;
				j = 2 * j;
			}
		}
		i--;
		j = 2 * i;
	}
}
void heap::insert(int x)
{
	last++;
	A[last] = x;
	//insertFix(last);
}
void heap::insertFix(int n)
{
	int temp = A[n];
	int i = n;
	while (i > 1 && temp > A[i / 2])
	{
		A[i] = A[i / 2];
		i = i / 2;
	}
	A[i] = temp;
}
void heap::Delete()
{
	int x, i, j;
	x = A[1];
	A[1] = A[last];

	i = 1;
	j = 2 * i;
	while (j < last)
	{
		if (A[j + 1] > A[j])
			j = j + 1;

		if (A[i] < A[j])
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i = j;
			j = 2 * j;
		}
		else
			break;
	}
	A[last--] = x;
}
void heap::heapsort()
{
	int last1 = last;
	while (last > 0)
	{
		Delete();
	}
	for (int j = 1; j <= last1; j++)
	{
		cout << A[j] << " ";
	}
	cout << endl;
}

void heap::print()
{

	for (int j = 1; j <= last; j++)
	{
		cout << A[j] << " ";
		if (j == 1 || j == 3 || j == 7)
			cout << endl;
	}
	cout << endl;
}

int main()
{
	heap hh;

	for (int i = 1; i <= 8; i++)
		hh.insert(40 * i);

	hh.heapify();

	cout << endl;

	hh.print();

	// hh.heapsort();

	return 0;
}