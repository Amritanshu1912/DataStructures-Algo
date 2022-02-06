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
	node *head;
public:
	LL(){head=NULL;}
	LL(int x);
	~LL();

	node* getH(){return head;}
	void setH(node* n ){this->head = n;}
	void Display();
	int len();

};

LL::LL(int x){

	node* last = NULL;
	for(int i =1; i<=x; i++){
		if(i==1){
			node* t =new node;
			t->data = 10*i;
			t->next = NULL;
			t->prev = NULL;
			head = t;
			last = head;
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
	node*p = head;
	while(p->next!=NULL){
		p = p->next;
	}
	p->next = head;
	head->prev = p;

}
LL::~LL(){
	node*p = head;
	while(head){
		head= head->next;
		delete p;
		p = head;
	}
}
void LL::Display(){
	node* p = head;
	do{
		cout<<p->data<<"  ";
		p=p->next;
	} while(p!=head);

	cout<<endl;
}
int LL::len(){
	int len =0; node*p = head;
	do{
		len++;
		p=p->next;
	}while(p!=head);
	return len;
}



int main()
{
	LL dl(5);

	dl.Display();
	cout<<"length : "<<dl.len()<<endl;
	cout<<dl.getH()->prev->data;



return 0;
}