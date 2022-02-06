#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LowerTri{
	private:
	int n;
	int *A;

	public:
	LowerTri(){
		n = 2;
		A = new int [n*(n+1)/2];
	}
	LowerTri(int n){
		this-> n =n;
		A = new int [n*(n+1)/2];
	}
	void set(int i,int j , int x);
	int get(int i, int j);
	void Display();
	~LowerTri(){delete []A;}
};

void LowerTri::set(int i, int j, int x){
	if(i>=j)
	A[(i*(i-1)/2) + (j-1)] = x;
}

int LowerTri::get(int i, int j){
	if(i>=j)
		return A[(i*(i-1)/2) + (j-1)];
	else 
		return -1;
}

void LowerTri::Display(){
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i>=j) 
			cout<<A[(i*(i-1)/2) + (j-1)]<<" ";
			else 
			cout<<"0"<<" ";
		}
		cout<<endl;
	}
	cout<<""<<endl;
}

int main()
{
	system("CLS");

	int x;
	cout<<"Enter dimension of  matrix"<<endl;
	cin >> x;
	LowerTri  m(x);

	cout<<"Enter all elements"<<endl;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j<=i; j++)
		{
			int k;					
			cin>>k;
			m.set(i,j,k);
		}
	}
	cout<<endl;

	m.Display();

return 0;
}