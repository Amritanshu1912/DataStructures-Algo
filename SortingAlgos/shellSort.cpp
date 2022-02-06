#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

void shellSort(int A[], int size)
{
	int gap = size / 2;
	while (gap > 0)
	{
		int i = 0;
		int j = 0;
		while (i < size - gap)
		{
			j = i;
			while (j >= 0 && A[gap + j] < A[j])
			{
				int temp = A[gap + j];
				A[gap + j] = A[j];
				A[j] = temp;
				j = j - gap;
			}
			i++;
		}
		gap = gap / 2;
	}
	cout << endl;
	cout << "Sorted Array  :  ";
	for (int i = 0; i < size - 1; i++)
	{
		cout << A[i] << ", ";
	}
	cout << A[size - 1];
	cout << endl;
	cout << endl;
}
bool checkSorted(int A[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			cout << i << "  not sorted";
			return 0;
		}
	}
	return 1;
}
int main()
{
	int A[] = {96, 55, 75, 19, 28, 83, 54, 97, 66, 22, 84, 88, 24, 74, 69, 10, 4};
	int size = sizeof(A) / sizeof(A[0]);

	shellSort(A, size);

	checkSorted(A, size) ? cout << "sorted" : cout << "not sorted";

	return 0;
}