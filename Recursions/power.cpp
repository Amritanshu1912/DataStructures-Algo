#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int power(int n, int m){

	if(m<=0)
	 return 1;
	else
	return power(n,m-1)*n;
}

int main()
{
	int n ,m;
	cout<<"Enter two  integers"<<endl;
	cin>> n >> m;
	int res = power(n,m);
	cout<<res;
	return 0;
  
}