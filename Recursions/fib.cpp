#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int fib(int n ){
	if(n<=0)
	return 0;
	else if(n==1)
	return 1;
	else
	return fib(n-1) + fib(n-2);
}

int main()
{
	cout<<"enter a number "<<endl;
	int num ;
	cin>> num;
	cout<<fib(num);
  

return 0;
}