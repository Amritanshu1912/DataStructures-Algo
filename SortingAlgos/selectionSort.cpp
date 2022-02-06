#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//find min in unsorted array
//swap with first element of unsorted array
//unsorted array reduces by one element

void sort(int Arr[], int n)
{
	cout << "" << endl;
	for (int i = 0; i < n; i++)
	{
		int j, k;
		for (j = k = i; j < n; j++)
		{
			if (Arr[j] < Arr[k])
			{
				k = j;
			}
		}
		int temp = Arr[i];
		Arr[i] = Arr[k];
		Arr[k] = temp;

		cout << Arr[i] << " ";
	}
}

int main()
{
	int arr[16] = {14, 77, 22, 36, 17, 34, 89, 65, 55, 6, 33, 9, 64, 16, 68, 74};
	sort(arr, 16);

	return 0;
}