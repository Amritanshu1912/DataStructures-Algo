#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
public:
	int col;
	int val;
	node* next;
};
class sArray{
private:
	static int m;
	
public:
	node* arr[5] = {NULL};
	sArray(){cout<<"pass size while initializing object!"; return;}
	sArray(int );
	~sArray();

	void Display();
};
sArray::sArray(int m){
	
	int num;
	cout<<"enter no. of elements : ";
	cin>>num;
	int i, j , data; 
	for(int k =0; k<num; k++){
		cout<<"Enter row, coulumn and value for element " <<k+1<<" : ";
		cin >> i >> j >> data;
		if(i>=m || j>=m){
			cout<<"Enter valid row and column!"<<endl;
			k--;
		}
		else{
			if(arr[i] == NULL){
			node * t = new node;
			t->col= j;
			t->val = data;
			t->next = NULL;
			arr[i] = t;
			}
			else{
				node *t = new node;
				t->col= j;
				t->val = data;
				t->next = NULL;
				node* p= arr[i];
				while(p){
					p = p->next;
				}
				p->next = t;
			}
		}
	}
}
sArray::~sArray(){
	for(int i =0; i<5; i++){
		node *p = arr[i];
		while(arr[i]!=NULL){
			arr[i]= arr[i]->next;
			delete p;
			p = arr[i];
		}
	}
}
void sArray::Display(){
	
	for(int k =0; k<5; k++){
		node *p = arr[k]; 
		for(int l =0; l<5; l++){
			if(p && l == p->col){
				cout<<p->val<<" ";
				p=p->next;
			}
			else
				cout<< "0 ";
		}
		cout<<endl;
	}
}
int main()
{
	sArray A(5);
	A.Display();
	A.~sArray();
	
	//your_code_here

return 0;
}