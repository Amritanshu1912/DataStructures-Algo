#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class node{
public:
	char data;
	node *next;
};

class stak{
private:
	node *top = NULL;

public:
	stak(){top = NULL;};
	stak(int);
	~stak();

	void push(char);
	char pop();
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

void stak::push(char x){
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
char stak::pop(){
	char x;
	if(top == NULL){
		cout<<"stak underflow"<<endl;
	}
	else{
		node * p = top;
		top = top->next;
		x = p->data;
		delete p;
		cout<<"\t Popped element is : "<< x<<endl;
	}
	return x;
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

int isBalance(string exp){
	stak st;
	for(int i =0; i<exp.length();i++){
		if (exp[i]=='(')
			st.push(exp[i]);
		else if (exp[i]==')'){
			if(st.isEmpty()) return false;
			st.pop();
		}
	}
	if(st.isEmpty())
		return true;
	else
		return false;
}
int isBalance1(string exp){
	stak st;
	for(int i =0; i<exp.length();i++){
		if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
			st.push(exp[i]);
		else if (exp[i]==')' || exp[i]==']' || exp[i]=='}'){
			if(st.isEmpty()) return false;
			char c = st.pop();
			char x;
			if(c == '(') x = ')';
			else if(c == '[') x = ']';
			else if(c == '{') x = '}';
			if(exp[i]!=x)
			 return false;
		}
	}
	if(st.isEmpty())
		return true;
	else
		return false;
}
int main()
{
	string test;
	cout<<"Enter string : ";
	cin>>test;

	int x = isBalance1(test);
	cout<< x;

return 0;
}