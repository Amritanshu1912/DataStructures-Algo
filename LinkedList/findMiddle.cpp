#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
public:

	int data;
	node *next;  //self referential structure
};

class LL{
private:
	node * head;
public:
	LL(){head == NULL;}
	LL(int );
	~LL();
	
	node* getH(){return head;}
	void setH(node* n ){this->head = n;}	

	//node* create(node* );
	//void del(node *);
	void display();
	int len(node*);
	void findMid( );
};
LL::LL(int x){
	node* last = NULL;
	for(int i =0; i<x; i++){
		if(i==0){
			node* t =new node;
			t->data = 10;
			t->next = NULL;
			head = t;
			last = head;
		}
		else{
			node* t = new node;
			t->data = 10*i+10;
			t->next = NULL;
			last->next = t;
			last = t;
		}
	}
}
LL::~LL(){
	node*p = head;
	while(head){
		head= head->next;
		delete p;
		p = head;
	}
}

void LL::display()
{
	node* p = head;
	while(p){
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}
int LL::len(node * n)
{
	if(n==0)
	return 0;
	else
	return len(n->next)+1;
}
void LL::findMid()
{
	node* p, *q;
	p = head;
	q = head;
	while(p!=NULL){
		p=p->next;
		if(p!=NULL)
			p=p->next;
		if(p!=NULL)
			q = q->next;
	}
	cout<<"Middle node is : "<<q->data<<endl;
}
// node* create(node* n)
// {
// 	node *temp = new node;
// 	cout<<"enter element  ";
// 	cin>>temp->data;
// 	temp->next = NULL;
// 	static node* last;
// 	if (n==NULL){
// 		n = temp;
// 		last = temp ;
// 	}
// 	else{
// 		last->next = temp;
// 		last  = temp ;
// 	}
// 	return n;
// }

int main()
{
	
	int num;
	cout<<"enter no. of elements - ";
	cin>>num;
	LL l1(num);

	l1.display();
	cout<<"Length - "<< l1.len(l1.getH())<<endl;
	
	l1.findMid();



return 0;
}

