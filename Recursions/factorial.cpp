#include<iostream>
using namespace  std;

int fact(int n){
	if(n<1)
	return 1;
	else
	return n*fact(n-1);
}


int main(){
	int num;
	cout<<"Enter a number between 0 to 100"<<endl;
	cin>>num;
	int res = fact(num);
	cout<< res <<endl;

	return 0;
}