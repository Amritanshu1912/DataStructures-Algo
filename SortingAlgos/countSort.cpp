#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int A[] = {19, 12, 15, 2, 5, 14, 8, 9, 4, 6, 2, 6, 13, 6, 10, 11};
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

int findmax(int A[])
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
void countSort(int A[])
{

	int sizeCount = findmax(A);
	int count[sizeCount + 1] = {0};

	for (int i = 0; i < sizeCount + 1; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		count[A[i]]++;
	}
	int j = 0;
	int i = 0;
	while (j < sizeCount + 1)
	{
		if (count[j] > 0)
		{
			A[i++] = j;
			count[j]--;
		}
		else
		{
			j++;
		}
	}
}
int main()
{

	countSort(A);
	Display(A);

	return 0;
}