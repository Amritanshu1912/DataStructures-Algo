#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int A[13] = {7, 12, 23, 56, 65, 76, 10, 27, 39, 44, 88, 91, 98};
int size = sizeof(A) / sizeof(A[0]);

void Display(int C[])
{
	cout << endl;
	cout << "Sorted Array :	";
	for (int i = 0; i < size; i++)
	{
		cout << C[i] << " ";
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

	Display(mergesort(A, size));

	return 0;
}