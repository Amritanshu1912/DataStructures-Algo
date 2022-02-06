#include<iostream>
using namespace  std;

int sum(int n){
	if(n<1)
	return 0;
	else
	return n + sum(n-1);
}


int main(){
	int num;
	cout<<"Enter a number between 0 to 100"<<endl;
	cin>>num;
	int res = sum(num);
	cout<< res <<endl;

	return 0;
}