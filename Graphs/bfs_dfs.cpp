#include <bits/stdc++.h>
#include <iostream>
#include "QandStak_for_graph.h"

using namespace std;

void dfs_recursive(int i, int A[][8])
{
	static int visited[8] = {0};
	if (visited[i] == 0)
	{
		cout << i << " ";
		visited[i] = 1;

		for (int v = 1; v < 9; v++)
		{
			if (A[i][v] == 1 && visited[v] == 0)
			{
				dfs_recursive(v, A);
			}
		}
	}
}
void dfs_iterative(int i, int A[][8])
{

	int visited[8] = {0};
	stak s;

	cout << i << " ";
	s.push(i);
	visited[i] = 1;
	int u;

	while (!s.issEmpty())
	{

		u = s.getTop();
		for (int v = 1; v < 8; v++)
		{
			if (A[u][v] == 1 && visited[v] == 0)
			{
				s.push(v);
				cout << v << " ";
				visited[v] = 1;
				u = v;
				v = 0;
				// break;
			}
		}
		s.pop();
	}
}
void bfs(int i, int A[][8])
{ //    i  =  starting vertex
	que q;
	int visited[8] = {0};

	cout << endl;
	cout << "bfs : " << endl;

	cout << i << endl;
	visited[i] = 1;
	q.enq(i);

	while (!q.isEmpty())
	{
		int u = q.deq();
		for (int v = 0; v <= 8; v++)
		{
			if (A[u][v] == 1 && visited[v] == 0)
			{
				cout << v << " ";
				visited[v] = 1;
				q.enq(v);
			}
		}
		cout << endl;
	}
}
void compact_2_matrixAdj(int A[], int matrixAdj[][8])
{
	int i = 1;
	int j = 9;

	for (int i = 1; i <= 8; i++)
	{
		int u = i;
		for (int j = A[i]; j < A[i + 1]; j++)
		{
			int v = A[j];
			matrixAdj[u][v] = 1;
		}
	}
}
void displaymatrix(int matrixAdj[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << matrixAdj[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int matrixAdj[8][8] = {0};
	int CompactList[27] = {0, 9, 12, 14, 18, 21, 25, 26, 27, 2, 3, 4, 1, 3, 1, 2, 4, 5, 1, 3, 5, 3, 4, 6, 7, 5, 5};

	compact_2_matrixAdj(CompactList, matrixAdj);
	displaymatrix(matrixAdj);
	dfs_recursive(5, matrixAdj);
	cout << endl;
	dfs_iterative(5, matrixAdj);

	return 0;
}