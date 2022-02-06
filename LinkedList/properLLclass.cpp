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

	node* getH(){
		node * n = head;
		return n;
	}
	void Display();
	int Count();
	int rmax();
	int rmin();
	node* search( int);
	void Insert(int ,int );
	void InsertSorted(int);
	int del(int);
	int checkSorted();
	void removeDup();
	void reverseLL();
	void recReverse(node *,node*);

};
LinkedList::LinkedList(int x){
	node* last = NULL;
	for(int i =0; i<x; i++){
		if(i==0){
			node* t =new node;
			t->data = 7*i +4;
			t->next = NULL;
			head = t;
			last = head;
		}
		else{
			node* t = new node;
			t->data = 7*i +4;
			t->next = NULL;
			last->next = t;
			last = t;
		}
	}
}
LinkedList::~LinkedList(){
	node*p = head;
	while(head){
		head= head->next;
		delete p;
		p = head;
	}
}  

int LinkedList::Count(){
	node * n = head;
	int count=0;
	while(n!=NULL){
		count++;
		n = n->next;
	}
	return count;
}
int LinkedList::rmax(){
	node* n = head;
	int x = n->data;
	while (n!=NULL)
	{
		if(x<n->data)
			x=n->data;
		n=n->next;
	}
	return x;
}
int LinkedList::rmin(){
	
	node* n = head;
	int x = n->data;
	while (n!=NULL)
	{
		if(x>n->data)
			x=n->data;
		n=n->next;
	}
	return x;
}
node* LinkedList::search( int key){
	node* n =head;
	while (n!=NULL)
	{
		if(key == n->data)
			return (n);

		n = n->next;
	}
	return NULL;
}
void LinkedList::Insert(int num,int pos){
	if(pos==0){
		node* t = new node;
		t->data = num;
		t->next = head;
		head = t;
	}
	else{
		node* t = new node;
		node* n = head;
		for (int i = 0; i < pos-1 && n ; i++)
		{
			n = n->next;
		}
		if(n){
		t->data = num;
		t->next = n->next;
		n->next = t;
		}
	}
}
void LinkedList::InsertSorted(int num ){
	node *p = head;
	node* q = NULL;
	if(p==NULL){
		node* t = new node;
		t->data = num;
		t->next = NULL;
		head = t;
	}
	else{
		node* t = new node;
		
		while (p && p->data<num)
		{
			q=p;
			p = p->next;
		}
		if(head->data>=num){
		t->data = num;
		t->next = head;
		head = t;
		
		}
		else{
		t->data = num;
		t->next = q->next;
		q->next = t;
		}
	}
}
int LinkedList::del(int pos){
	int x;
	if (pos ==1 ){
		node* p  = head;
		head = head->next;
		x = p->data;
		delete p;
	}
	else if(pos!=1){
		node* p = head;
		node* q = NULL;
		for(int i =0; i < pos-1; i++){
			q= p ;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	return x;
}
int LinkedList::checkSorted(){

	int x = - 32768;
	node* p =head ;
	while(p!=NULL){
		if(p->data<x)
			return false;		
		x = p->data;
		p=p->next;
	}
	return true;
}
void LinkedList::removeDup(){

	node *p,*q;
	q = head->next;
	p = head;

	while(q!=NULL){
		if(q->data != p->data){
			p = q;
			q = q->next;
		}
		else{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}
void LinkedList::reverseLL(){
	node *p = head;
	node *q = NULL;
	node *r = NULL;

	while(p!= NULL){
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}
void LinkedList::recReverse(node *q,node* p){
	if(p!=NULL){
		recReverse(p,p->next);
		p->next = q;
	}
	else{
		head = q;
	}
}
void LinkedList::Display(){

	node* p = head;
	while(p){
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	system("CLS");
	
	cout<<"enter no. of elements - ";
	int x;
	cin>>x;
	LinkedList l(x);
	l.Display();
	cout<<endl; 
	
	int choice;
	cout<<"--------MENU--------"<<endl;
	cout<<"1. Insert"<<endl;
	cout<<"2. Count"<<endl;
	cout<<"3. MAX & MIN"<<endl;
	cout<<"4. Search"<<endl;
    cout<<"5. Display"<<endl;
	cout<<"6. Sorted Insert"<<endl;
	cout<<"7. Delete"<<endl;
	cout<<"8. Check if Sorted"<<endl;
	cout<<"9. Remove Duplicate"<<endl;
	cout<<"10. Reverse LL "<<endl;
	cout<<endl; 

	cout<<"Choose between 1-10 : ";
	cin>>choice;

	while(choice>=1&&choice<=10){

	switch (choice){
		case 1/* Insert at a position */:
		
			cout << "enter element and pos to insert - "<<endl;
			int pos;
			int nu ; 
			cin>>nu>>pos;
			l.Insert(nu,pos);/* code */
			l.Display();					
			break;
		
		case 2/* Count */:
			cout<<"count - "<< l.Count()<<endl;
			break;
		
		case 3/* Max-Min */:
			cout<<"MAX - "<<l.rmax()<<endl;
			cout<<"MIN - "<<l.rmin()<<endl;
			break;
		
		case 4/* Search */:
			node *key; int k;
			cout<<"enter key for search - ";
			cin >>k;
			key = l.search(k);
			if(key)
				cout<< "key is found - "<<key->data<<endl;
			else	
				cout<<"key is not found"<<endl;
			
			break;
		
		case 5/* Display */:
			l.Display();
			break;
		
		case 6/* Sorted_Insert in a sorted LL*/:
		
			cout << "enter element to insert - ";
			int nu1 ; 
			cin>>nu1;
			l.InsertSorted(nu1);
			l.Display();					
			break;
		
		case 7/*delete from a pos*/:
			int pos1;
			cout<<"Enter a position to delte node from - ";
			cin >> pos1;
			cout<<"Deleted element is - "<<l.del(pos1)<<endl;
			l.Display();					
			
			break;

		case 8/*Check if LL is Sorted*/:
			int flag ;
			flag = l.checkSorted();
			flag>0?cout<<"Sorted"<<endl:cout<<"not sorted"<<endl;
		
			break;

		case 9/*Remove Duplicate*/:
			
			l.removeDup();
			l.Display();
			break;

		case 10/*Reverse LL by reversing links*/:
			
			//l.reverseLL();

			l.recReverse(NULL,l.getH());
			l.Display();
			break;

		default:
			l.Display();					
			cout<<endl;

			break;
		}
	cout<<"Choose between 1-10 : ";
	cin>>choice;
	}
	cout<<"Aborting execution..."<<endl;

return 0;
}