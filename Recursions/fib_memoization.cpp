#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int F[20];

int fib(int n){
	
	if(n==0 && F[n]==-1){
		F[0]=0;
		return 0;
	}
	else if(n==1 && F[n]==-1){
		F[1]=1;
		return 1;
	}
	else{
		if(F[n-2]==-1)
		F[n-2]=fib(n-2);
		if(F[n-1]==-1)
		F[n-1]=fib(n-1);

		return F[n-1]+F[n-2];
	}

}

int main()
{
  for ( int i = 0; i < 20; i++)
	  F[i] =-1;
	
  int num;
  cout<<"enter a no. <=20"<<endl;
  cin>>num;
  cout<<fib(num);

return 0;
}