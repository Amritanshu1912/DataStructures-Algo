#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//push the max at the last of array at every pass
//unsorted array reduces by one element

void Bubble(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				int temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

int main()
{
	int Arr[16] = {14, 77, 22, 36, 17, 34, 89, 65, 55, 6, 33, 9, 64, 16, 68, 74};

	int n = sizeof(Arr) / sizeof(Arr[0]);

	Bubble(Arr, n);

	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
	cout << endl;

	return 0;
}