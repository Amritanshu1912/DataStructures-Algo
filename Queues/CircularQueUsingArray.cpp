#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class que{
private:
	int size ;
	int front = 0;
	int rear  = 0;
	int *q;
public:
	que(){size =0;}
	que(int );
	~que(){delete []q;}

	void enq(int);
	int deq();
	void display();
	int isEmpty();
	int isFull();
	
};
que::que(int x){
	size = x;
	this->q = new int [x];
}

void que::enq(int x){
	if(isFull()){
		cout<<"que is Full"<<endl;
	}
	else{
		rear = (rear+1)%size;
		q[rear] = x;
	}
}
int que::deq(){
	int x = -1;
	if(isEmpty()){
		cout<<"Que is  Empty"<<endl;
	}
	else{
		front = (front+1)%size;
		x = q[front];
	}
	return x;
}
void que::display(){
	int i=front+1;
	do{
		cout<<q[i]<<"  ";
		i = (i+1)%size;
	}while(i!=(rear+1)%size);
	cout<<endl;
}
int que::isEmpty(){
	if(front == rear)
	 return 1;
	else 
	 return 0;
}
int que::isFull(){
	if((rear+1)%size == front)
	 return 1;
	else 
	 return 0;
}

int main()
{
	que qu(5);
	qu.enq(1);
	qu.enq(2);
	qu.enq(3);
	qu.enq(4);
	//qu.enq(5);
	qu.display();

	qu.enq(6);
	qu.display();

	qu.deq();
	qu.display();
	
	qu.enq(6);
	qu.display();

	
return 0;
}