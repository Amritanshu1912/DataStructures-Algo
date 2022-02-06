#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int A[] = {14, 77, 22, 36, 17, 34, 89, 65, 55, 6, 33, 64, 16, 68, 74};
int size = sizeof(A) / sizeof(A[0]);

void Display(int A[])
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

void merged(int A[], int l, int m, int h)
{

	int c[size];
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= h)
	{
		if (A[i] < A[j])
		{
			c[k++] = A[i++];
		}
		else
		{
			c[k++] = A[j++];
		}
	}
	for (; i <= m; i++)
	{
		c[k++] = A[i];
	}
	for (; j <= h; j++)
	{
		c[k++] = A[j];
	}

	for (int z = l; z <= h; z++)
		A[z] = c[z];
}

void rMergeSort(int A[], int l, int h)
{

	if (l < h)
	{
		int mid = (l + h) / 2;
		rMergeSort(A, l, mid);
		rMergeSort(A, mid + 1, h);
		merged(A, l, mid, h);
	}
}

int *mergesort(int A[], int n)
{
	int i, l, m, h;
	int p = 2;
	while (p <= n)
	{
		for (i = 0; i < n - p + 1; i = i + p)
		{
			l = i;
			h = i + p - 1;
			m = (l + h) / 2;
			merged(A, l, m, h);
		}
		p = p * 2;
	}
	if (p / 2 < n)
	{
		merged(A, 0, (p / 2) - 1, n);
	}
	return A;
}

int main()
{
	rMergeSort(A, 0, size - 1);
	Display(A);

	return 0;
}