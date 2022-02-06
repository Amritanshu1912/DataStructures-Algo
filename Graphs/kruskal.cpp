//kruskals algo - select the min cost edge but it should not form a cycle

#include <bits/stdc++.h>
#include <iostream>
#define I INT16_MAX
using namespace std;

int edge[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
				  {2, 6, 3, 7, 4, 5, 7, 6, 7},
				  {25, 5, 12, 10, 8, 16, 14, 20, 18}};
int t[2][6];
int dsjt[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int included[9] = {0};

void uni(int u, int v) //weighted union of two dsjts
{
	if (dsjt[u] < dsjt[v])
	{
		dsjt[u] = dsjt[u] + dsjt[v];
		dsjt[v] = u;
	}
	else
	{
		dsjt[v] = dsjt[u] + dsjt[v];
		dsjt[u] = v;
	}
}

int find(int u) // to find if the vertices belong to different parents or same;if same then it will form a cycle
{
	int x = u;

	while (dsjt[x] > 0)
	{
		x = dsjt[x];
	}

	return x;
}

int main()
{
	int i = 0, j, k, n = 7, e = 9, min, u, v;
	while (i < n - 1)
	{
		min = I;
		for (int j = 0; j < e; j++)
		{
			if (included[j] == 0 && edge[2][j] < min)
			{
				min = edge[2][j];
				k = j, u = edge[0][j], v = edge[1][j];
			}
		}
		if (find(u) != find(v))
		{
			t[0][i] = u, t[1][i] = v;
			uni(find(u), find(v));
			i++;
		}
		included[k] = 1;
	}

	for (int i = 0; i < 6; i++) // display two nodes representing edges
		cout << t[0][i] << "--" << t[1][i] << endl;

	return 0;
}