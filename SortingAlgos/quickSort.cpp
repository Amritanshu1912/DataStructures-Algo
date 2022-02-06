#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int Partition(int A[], int l, int h)
{

	int pivot = A[l];
	int i = l;
	int j = h;
	while (i < j)
	{
		while (A[i] <= pivot)
			i++;

		while (A[j] > pivot)
			j--;

		if (i < j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	int temp1 = A[l];
	A[l] = A[j];
	A[j] = temp1;

	return j;
}
void quickSort(int A[], int l, int h)
{
	int j;
	if (l < h)
	{
		j = Partition(A, l, h);
		quickSort(A, l, j - 1);
		quickSort(A, j + 1, h);
	}
}

int main()
{
	int arr[16] = {88, 77, 22, 36, 17, 34, 89, 64, 55, 6, 33, 9, 66, 16, 69, 61};

	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, 16);

	for (int i = 0; i < 16; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}