#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class que{
private:
	int size ;
	int front = -1;
	int rear  = -1;
	int *q;
public:
	que(){size =0;}
	que(int );
	~que(){delete []q;}

	void enq(int,int);
	int deq(int);
	void display();
	int isEmpty();
	int isFull();
	
};
que::que(int x){
	size = x;
	this->q = new int [x];
	
}

void que::enq(int end, int x){
	if(isFull()){
		cout<<"que is Full"<<endl;
	}
	else {
		if(end == 0){
			if(front!=-1){
				q[front] = x;
				front--;
			}
			else{
				cout<<"No space to insert at front"<<endl;
			}
		}
		else if(end==1){
			rear++; 
			q[rear] = x;
		}
	}
}
int que::deq(int end1){
	int x = -1;
	if(isEmpty()){
		cout<<"Que is  Empty"<<endl;
	}
	else{
		if(end1 == 0){
			front++;
			x = q[front];
			q[front] = -1;
		}
		else if(end1 == 1){
			x = q[rear];
			q[rear] = -1;
			rear--;
		}
	}
	return x;
}
void que::display(){
	for(int i =front +1; i<=rear; i++){
		cout<<q[i]<<"  ";
	}
	cout<<endl;
}
int que::isEmpty(){
	if(front == rear)
	 return 1;
	else 
	 return 0;
}
int que::isFull(){
	if(rear == size -1)
	 return 1;
	else 
	 return 0;
}

int main()
{
	que qu(5);
// 0 : for front & 1 for rear
// for enq and deq operations

	qu.enq(1,1);
	qu.enq(1,2);
	qu.enq(1,3);
	qu.enq(1,4);
	qu.enq(0,5);
	qu.display();
	qu.deq(0);
	qu.enq(0,8);
	qu.display();

	qu.deq(1);
	qu.display();
	
	qu.enq(1,9);
	qu.display();

	
return 0;
}