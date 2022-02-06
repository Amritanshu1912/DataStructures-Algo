#include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;

class stak{
private:
	
	int size;
	int top =-1;
	int *s;
public:
	stak(){size = 0;};
	stak(int,int);
	~stak(){delete []s;}
	int getTop(){return top;}

	void Display();
	void push(int);
	int pop();
	int isEmpty();
	int isFull();
	int peek(int);
};
stak::stak(int size, int x){
	this->size = size;
	this->s = new int [size];


	for(int i=0; i < x; i++){
		// int x;
		// cout<<"Enter element "<<i+1<<" : ";
		// cin>>x;
		push(7*i + 1);
		// // cin>>s[i];
		// // top++;
	}
}
void stak::Display(){
	for (int i = top; i >= 0; i--)
	{
		cout<<s[i]<<endl;
	}

}
int stak::isEmpty(){
	int x = getTop() == -1?  1 :  0;
	return x;
}
int stak::isFull(){
	int x = getTop() == size - 1 ?  1 :  0;
	return x;
}
void stak::push(int x){
	
	if(top == size-1)
		cout<<"Stak overflow"<<endl;
	else{
		top++;
		s[top] = x;
	}
}
int stak::pop(){
	int x = -1;
	if(top==-1){
		cout<<"stak underflow"<<endl;
	}
	else{
		x = s[top];
		top--;
	}
	return x;
}
int stak::peek(int pos){
	
	// top+1 - pos = index
	if((top + 1 - pos)<0){
		cout<<"INVALID POSITION !!!"<<endl;
		return -1;
	}
	else
		return s[top+1 - pos]; 
}


int main()
{
	int size,n;
	cout<<"Enter size of staack and no. of Elements : ";
	cin>>size>>n;
	if(size<n){
		cout<<"size of staack is less than no. of elements!"<<endl;
		return 0;
	}
	stak stk(size,n);
	
	stk.Display();




return 0;
}