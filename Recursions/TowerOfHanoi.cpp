#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void toh(int n,int A, int B,int C ){
	if(n>0){
	toh(n-1,A,C,B);
	cout<<"from "<<A<<" to "<<C<<endl;
	toh(n-1,B,A,C);
	}
}

int main()
{
	int num;
	cout<< "enter no. of disks"<<endl;
	cin>>num;
	toh(num,1,2,3);	

return 0;
}