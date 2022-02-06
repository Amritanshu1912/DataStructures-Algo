#include <bits/stdc++.h>
#include <iostream>
#define I INT16_MAX

using namespace std;

int cost[8][8] = {{I, I, I, I, I, I, I, I},
				  {I, I, 25, I, I, I, 05, I},
				  {I, 25, I, 12, I, I, I, 10},
				  {I, I, 12, I, 8, I, I, I},
				  {I, I, I, 8, I, 16, I, 14},
				  {I, I, I, I, 16, I, 20, 18},
				  {I, 05, I, I, I, 20, I, I},
				  {I, I, 10, I, 14, 18, I, I}};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][6]; //6 bcz 7 vertices and 7-1 edges. 2d matrix for storing strt and end of 6 such edges

int main()
{
	//find min cost edge in upper triangle
	int min = I, u = 0, v = 0;
	for (int i = 1; i < 8; i++)
	{
		for (int j = i; j < 8; j++)
		{
			if (cost[i][j] < min)
			{
				min = cost[i][j];
				u = i, v = j;
			}
		}
	}
	//putting min cost between nodeu and v in t's first col
	t[0][0] = u, t[1][0] = v;
	near[u] = 0, near[v] = 0;

	// checking every node's cost from u  and v
	for (int i = 1; i < 8; i++)
	{
		if (near[i] != 0)
		{
			if (cost[i][u] < cost[i][v])
				near[i] = u;
			else
				near[i] = v;
		}
	}
	//
	for (int i = 1; i < 6; i++)
	{
		int min = I, k;
		for (int j = 1; j < 8; j++) // finding min cost in near array
		{
			if (near[j] != 0 && cost[j][near[j]] < min)
			{
				min = cost[j][near[j]];
				k = j; //make k point at that index
			}
		}
		t[0][i] = k;
		t[1][i] = near[k]; //filling it in array t
		near[k] = 0;	   //marking it as visited

		for (int j = 1; j < 8; j++) // updating near array by checking distance of every unvisted node form k
		{
			if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
				near[j] = k;
		}
	}
	for (int i = 0; i < 6; i++) // display two nodes representing edges
		cout << t[0][i] << "--" << t[1][i] << endl;

	return 0;
}