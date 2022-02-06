#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
public:
	int data;
	node *next;
	node *prev;
};

class LL{
private:
	node *first;
public:
	LL(){first=NULL;}
	LL(int x);
	~LL();

	node* getH(){return first;}
	void setH(node* n ){this->first = n;}
	void Display();
	int len();
	void Insert(int, int);
	void Del();
	void Reverse();
};

LL::LL(int x){

	node* last = NULL;
	for(int i =1; i<=x; i++){
		if(i==1){
			node* t =new node;
			t->data = 10*i;
			t->next = NULL;
			t->prev = NULL;
			first = t;
			last = first;
		}
		else{
			node* t = new node;
			t->data = 10*i ;
			t->next = NULL;
			t->prev = last;
			last->next = t;
			last = t;
		}
	}
}
LL::~LL(){
	node*p = first;
	while(first){
		first= first->next;
		delete p;
		p = first;
	}
}
void LL::Display(){
	node* p = first;
	while(p){
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}
int LL::len(){
	int len =0; node*p = first;
	while(p){
		len++;
		p=p->next;
	}
	return len;
}
void LL::Insert(int pos, int x){
	if(pos<0 || pos>len())
		return;
	if(pos==0){
		node * t = new node;
		t->prev = NULL;
		t->data = x;
		t->next = first;
		first->prev = t;
		first =t;
	}
	else{
		node*t = new node;
		node *p = first;
		t->data = x;
		for(int i=0; i<pos-1; i++ ){
			p = p->next;
		}
		t->next = p->next;
		t->prev = p;
		if(p->next)
			p->next->prev = t;
		p->next = t;
	}
}
void LL::Del(){
	int pos;
	cout<<"enter index to delete : ";
	cin>>pos;
	
	
	if(pos<1 || pos>len()){
		cout<<"--------Invalid Index--------"<<endl;
		return ;
	}
	int x ;
	if(pos==1){
		node*p = first;
		first = first->next;
		x = p->data;
		delete p;
		if(first) 
			first->prev = NULL;
	}
	else{
		node* p = first;
		for(int i =0 ; i<pos-1; i++){
			p = p->next;
		}
		p->prev->next = p->next;
		if(p->next)
			p->next->prev = p->prev;
		x = p->data;
		delete p;
	}
	cout<<"Deleted element is : "<< x<<endl;
	return;
}
void LL::Reverse(){
	node * p = first;
	while(p!=NULL){
		node *temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if(p!=NULL && p->next ==NULL)
			first = p;
	}
}

int main()
{
	LL dl(5);

	dl.Display();
	//cout<<"length : "<<dl.len()<<endl;

	// dl.Insert(5,22);
	// dl.Display();
	
	// dl.Del();
	// dl.Display();

	// dl.Reverse();
	// dl.Display();

return 0;
}