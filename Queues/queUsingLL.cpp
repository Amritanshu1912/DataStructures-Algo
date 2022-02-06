#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class node{
public: 
	int data;
	node* next;
};

class que{
private:
	node* front = NULL ;
	node* rear = NULL ;
	int *q;
public:
	que(){front =NULL;rear =NULL;}
	que(int );
	~que();

	void enq(int );
	int deq();
	void display();
	int isEmpty();
	int isFull();
	
};

que::que(int x ){
	cout<<"enter "<<x<<" elements "<<endl;
	//int y;
	for (int i = 0; i<x ;i++){
		//cin>>y;
		enq(3*i);
	}
	cout<<endl;
}
que::~que(){
	node* p = front;
	while(front){
		front = front->next;
		delete p;
		p = front;
	}
}

void que::enq(int x){
	node *t = new node;
	t->data = x;
	t->next =NULL;
	if (front == NULL){
		front =t;
		rear = t;
	}
	else{
		rear->next = t ;
		rear = t;
	}
}
int que::deq(){
	int x = -1;
	node* p;
	if (isEmpty()){
		cout<<"que is Empty"<<endl;
	}
	else{
		p = front;
		front = front->next;
		x = p->data;
		delete p;
	}
	return x;
}
void que::display(){
	if(isEmpty())
		cout<<"que is empty,nothing to show!!"<<endl;
	else{
		node *p = front;
		while(p != NULL){
			cout<<p->data<<"  ";
			p = p->next;
		}
		cout<<endl;
	}
}
int que::isEmpty(){
	if (front==NULL)
	return 1;
	else return 0;
}
int que::isFull(){
	node *test = new node;
	if(test==NULL)
		return 1;
	else 
		return 0;
}

int main()
{
	que qu(5);
	
	qu.display();
	qu.enq(555);
	qu.display();
	qu.deq();
	qu.display();
	
return 0;
}