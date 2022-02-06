#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
	public:
	int data;
	node* next;

	node(){

	}
	~node(){

	}

	void concat(node*);
	void display(node*);
	node* mergeLL();

}*first = NULL,*second= NULL;

void concat(node * p){
	while(p->next!=NULL){
		p=p->next;
	}
	p->next = second;
}

void display(node * p){
	
	if(p!=NULL){
		cout<<p->data<<"  ";
		display(p->next);
	}
}
node* mergeLL(){

	node *third = NULL, *last = NULL;

	if(first->data<second->data){
		third = first;
		last = first;
		first = first->next;
		last->next = NULL;
	}
	else{
		third = second;
		last = second;
		second =  second->next;
		last->next = NULL;
	}
	while(first!=NULL && second !=NULL){
		
		if(first->data<second->data){
			last->next =first;
			last = first;
			first = first->next;
			last->next = NULL;
		}
		else{
			last->next =second;
			last = second;
			second =  second->next;
			last->next = NULL;
		}
	}
	if(first==NULL)
		last->next = second;
	else if(second==NULL)
		last->next = first;
	return third;
}
int main()
{
	
	node * last =NULL;
	for(int i =0; i < 7; i++){
		node * t = new node;
		if(i==0){
			node* t1 = new node;
			t1->data = 1;
			t1->next = NULL;
			first = t1;
			last = first;
		}	
		else{
			node*t1 = new node;
			t1->data = 2*i+1;
			last->next=t1;
			t1->next=NULL;
			last= t1;
		}

	}
	
	node* last2= NULL;
	for(int j = 0; j<5;j++){
		if(j==0){
			node* t2 = new node;
			t2->data = 2*j+2;
			t2->next = NULL;
			second = t2;
			last2 = second;
		}	
		else{
			node * t2 = new node;
			t2->data = 2*j +2;
			t2->next = NULL;
			last2->next = t2;
			last2 = t2;
		}
	}
	
	//your_code_here
	display(first);
	cout<<endl;

	display(second);
	cout<<endl;
	node * third;
	third = mergeLL();

	display(third);
	cout<<endl;
return 0;
}
