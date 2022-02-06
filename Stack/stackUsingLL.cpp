#include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;

class node{
public:
	int data;
	node *next;
};

class stak{
private:
	node *top = NULL;

public:
	stak(){top = NULL;};
	stak(int);
	~stak();

	void push(int);
	void pop();
	void Display();
	int peek(int);
	int getTop();
	int isEmpty();
	int isFull();
};
stak::stak(int x){
	for(int i=0; i < x; i++){
		// int x;
		// cout<<"Enter element "<<i+1<<" : ";
		// cin>>x;
		push(7*i + 1);
	}
}
stak::~stak(){
	node* p = top;
	while(top){
		top = top->next;
		delete p;
		p = top;
	}
}

void stak::push(int x){
	node *test = new node;
	if(test == NULL){
		delete test;
		cout<<"Stak overflow"<<endl;
	}
	else{
		delete test;
		cout<<"Pushing element : "<<x<<endl;
		node *t =  new node;
		t->data = x;
		t->next = top;
		top = t;
	}
}
void stak::pop(){
	int x;
	if(top == NULL){
		cout<<"stak underflow"<<endl;
	}
	else{
		node * p = top;
		top = top->next;
		x = p->data;
		delete p;
		cout<<"Popped element is : "<< x<<endl;
	}
}
void stak::Display(){
	node *p = top;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p = p->next;
	}
	cout<<endl;
}
int stak::peek(int pos){
	node * p = top;
	for (int i = 0; p!=NULL && i < pos - 1; i++)
		p = p->next;
	
	if(p != NULL)
		return p->data;
	else {
		cout<<"INVALID POSITION !!!"<<endl;
		return -1;
	}
}
int stak::getTop(){
	if(top)
		return top->data;
	return -1;
}
int stak::isEmpty(){
	return  top ? 0 : 1;
}
int stak::isFull(){
	node * test = new node;
	int x = test == NULL ?  1 :  0;
	delete test;
	return x;
}

int main()
{
	int n;
	cout<<"Enter no. of Elements : ";
	cin>>n;

	stak stk(n);
	
	cout<<endl;
	stk.Display();
	//cout<<"Top is pointing on element : "<<stk.getTop()<<endl;	
	//cout<<stk.isEmpty();
	//cout<<stk.isFull();
	stk.push(111);
	stk.Display();
	stk.pop();
	stk.pop();
	//cout<<"peeking now : "<<stk.peek(5) << endl;



return 0;
}