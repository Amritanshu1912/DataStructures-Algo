#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
public:
	int data;
	node *next;
};

class LinkedList{

private:
	node * head;
public:
	LinkedList(){head=NULL;}
	LinkedList(int x);
	~LinkedList();

	node* getH(){return head;}
	void setH(node* n ){this->head = n;}
	
	int isLoop(node*);
	void CDisplay(node*);
	void RecCDisplay(node* p);
	void Insert(int ,int );
	int del(int);


};

LinkedList::LinkedList(int x){
	node* last = NULL;
	for(int i =0; i<x; i++){
		if(i==0){
			node* t =new node;
			t->data = 1;
			t->next = NULL;
			head = t;
			last = head;
		}
		else{
			node* t = new node;
			t->data = 5*i ;
			t->next = NULL;
			last->next = t;
			last = t;
		}
	}
	node *t1;
	t1= head;
	while(t1->next!=NULL){
		t1 = t1->next;
	}
	t1->next = head;
}
LinkedList::~LinkedList(){
	node*p = head;
	while(head){
		head= head->next;
		delete p;
		p = head;
	}
}

int LinkedList::isLoop(node*f){
	node*p,*q;
	p=q=f;
	do
	{
		p = p->next;
		q = q->next;
		q = q!=NULL?q->next:NULL;
	} while (p && q && p!=q);
	if(p==q)
	return 1;
	else 
	return 0;
}
void LinkedList::CDisplay(node* p){
	do{
		cout<<p->data<<"  ";
		p=p->next;
	} while(p!=head);

	cout<<endl;
}
void LinkedList::RecCDisplay(node* p){
	static int flag =0;
	if(p!=head || flag==0){
		flag=1;
		cout<<p->data<<"  ";
		RecCDisplay(p->next);
	}	
	flag =0;
}	
void LinkedList::Insert(int x,int pos){
	
	if(pos==0){
		node * p = head;
		node * t = new node;
		t->data = x;
		t->next = head;
		while(p->next!=head)
			p = p->next;
		
		p->next = t;
		head = t;
		//setH(t) ;
	}
	else{
		node *t = new node;
		node *p = head;

		for(int i=0; i<pos-1;i++){
			p=p->next;
		}
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}
int LinkedList::del(int pos){
	int x ;
	if(pos == 1){
		node *p = head;
		
		do{
			p=p->next;
		}while(p->next!=head);

		p->next = head->next;
		x = head->data;
		p = head;
		head = head->next;
		delete p;
	}
	else{
		node* p = head; 
		node * q= NULL;
		for(int i =0; i<pos-1; i++){
			q = p;
			p=p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	return x;
}

int main()
{	
	LinkedList l1(9);
	l1.CDisplay(l1.getH());

	l1.isLoop(l1.getH())==1? cout<<"Loop found" : cout<<"Loop not found";
	cout<<endl;

	//l1.CDisplay(l1.getH());

	//l1.Insert(111,0);	//	Insert(Element, position);

	// l1.CDisplay(l1.getH());

	cout<< "Deleted element is : "<< l1.del(1)<<endl; 

	l1.CDisplay(l1.getH());


return 0;
}