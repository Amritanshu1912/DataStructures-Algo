#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Matrix{
	private:
	int n;
	int *A;

	public:
	Matrix(){
		n = 2;
		A = new int [n];
	}
	Matrix(int n){
		this-> n =n;
		A = new int [n];
	}
	void set(int i,int j , int x);
	int get(int i, int j);
	void Display();
	~Matrix(){delete []A;}
};

void Matrix::set(int i, int j, int x){
	if(i==j)
	A[i-1] = x;
}
int Matrix::get(int i, int j){
	if(i==j)
	return i-1;
	else 
	return -1;
}
void Matrix::Display(){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i==j) 
			cout<<A[j-1]<<" ";
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

	Matrix  m(4) ;
	m.set(0,0,1);
	m.set(1,1,2);
	m.set(2,2,3);
	m.set(3,3,4);

	m.Display();

return 0;
}