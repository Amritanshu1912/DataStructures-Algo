#include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;
class sp{
public:
	int top =-1;
	int*s;
	int getTop(){return top;}
};
class que{
private:
	
	int size;
	sp *s1;
	sp *s2;
public:
	que(){size = 0;};
	que(int,int);
	~que(){delete []s1; delete[]s2;}
	

	void enque(int );
	int deque();
	void Display();
	void push(sp*, int);
	int pop(sp*);
	int isEmpty(sp*);
	int isFull(sp*);

};
que::que(int size, int x){
	this->size = size;
	s1 = new sp ;
	s2 = new sp;
	this->s1->s = new int [size];
	this->s2->s = new int [size];

	for(int i=0; i < x; i++){
		// int x;
		// cout<<"Enter element "<<i+1<<" : ";
		// cin>>x;
		push(s1,7*i + 1);
		// // cin>>s[i];
		// // top++;
	}
}
void que::enque(int x){
	push(s1,x);
}
int que::deque(){
	int x = -1;
	if(isEmpty(s2)){
		if(isEmpty(s1)){
			cout<<"que empty";
			return x;
		}
		else{
			while(!isEmpty(s1)){
				push(s2,pop(s1));
			}
		}
	}
	return pop(s2);
}
void que::Display(){
	cout<<"S1 elements are : "<<endl;
	for (int i = s1->top; i >= 0; i--)
	{
		cout<<s1->s[i]<<endl;
	}
	cout<<endl;
	cout<<"S2 elements are : "<<endl;
	for (int i = s2->top; i >= 0; i--)
	{
		cout<<s2->s[i]<<endl;
	}

}
int que::isEmpty(sp *s){
	int x = s->getTop() == -1?  1 :  0;
	return x;
}
int que::isFull(sp *s){
	int x = s->getTop() == size - 1 ?  1 :  0;
	return x;
}
void que::push(sp *s, int x){
	
	if(s->top == size-1)
		cout<<"Stak overflow"<<endl;
	else{
		s->top++;
		s->s[s->top] = x;
	}
}
int que::pop(sp * s){
	int x = -1;
	if(s->top==-1){
		cout<<"stak underflow"<<endl;
	}
	else{
		x = s->s[s->top];
		s->top--;
	}
	return x;
}


int main()
{
	int size,n;
	cout<<"Enter size of staack and no. of Elements : ";
	cin>>size>>n;
	if(size<n){
		cout<<"size of staack is less than no. of elements!"<<endl;
		return 0;
	}
	que stk(size,n);
	stk.Display();

	stk.enque(999);
	cout<<"dequeing : "<<stk.deque()<<endl;
	
	stk.enque(777);
	stk.enque(666);
	stk.Display();




return 0;
}