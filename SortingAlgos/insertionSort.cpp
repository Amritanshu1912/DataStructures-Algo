#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void SelectionSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = A[i];
		int j = i - 1;
		while (temp < A[j] && j >= 0)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
	}
}

int main()
{
	int arr[16] = {14, 77, 22, 36, 17, 34, 89, 65, 55, 6, 33, 9, 64, 16, 68, 74};

	int size = sizeof(arr) / sizeof(arr[0]);
	SelectionSort(arr, size);

	for (int i = 0; i < 16; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}