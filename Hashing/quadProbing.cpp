#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int hsh(int key)
{
	return key % 10;
}

int probe(int H[], int key)
{

	int index = hsh(key);
	int i = 0;

	while (H[(index + i * i) % 10] != 0)
		i++;

	return (index + i * i) % 10;
}

void insert(int H[], int key)
{
	int index = hsh(key);

	if (H[index] != 0)
	{
		index = probe(H, key);
	}
	H[index] = key;
}

int search(int H[], int key)
{
	int index = hsh(key);
	int i = 0;

	while (H[(index + i * i) % 10] != key && H[(index + i * i) % 10] != 0)
		i++;

	return (index + i * i) % 10;
}

void display(int ht[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << " : " << setw(2) << ht[i] << endl;
	}
	cout << endl;
}

int main()
{
	int ht[10] = {0};
	insert(ht, 12);
	insert(ht, 25);
	insert(ht, 35);
	insert(ht, 45);
	insert(ht, 85);

	display(ht);

	cout << "key found at : " << search(ht, 35);
	return 0;
}
