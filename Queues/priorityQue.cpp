#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
class qp{
public:
	int front = -1;
	int rear  = -1;
	int* A ;
};

class que{
private:
	int size ;
	
	qp *q1;
	qp *q2;
	qp *q3;
public:
	que(){size =0;}
	que(int );
	~que();

	void enq(int, int);
	int deq();
	void display();
	int isEmpty(qp*);
	int isFull(qp*);
	
};
que::que(int x){
	size = x;
	q1 = new qp;
	q1->A = new int [x];
	
	q2 = new qp;
	q2->A = new int [x];

	q3 = new qp;
	q3->A = new int [x];
}
que::~que(){
	delete []q1->A;
	delete []q2->A;
	delete []q3->A;
}

void que::enq(int y, int x ){
	int pri;
	if(x<10)pri = 1;
	else if(x<100)pri = 2;
	else{pri = 3;}
	
	if(pri==1){
		if(isFull(q1)){
		cout<<"cannot add "<<x<<" que1 is Full"<<endl;
		}
		else{
			q1->rear++; 
			q1->A[q1->rear] = x;
		}
	}
	else if(pri == 2){
		if(isFull(q2)){
		cout<<"cannot add "<<x<<" que2 is Full"<<endl;
		}
		else{
			q2->rear++; 
			q2->A[q2->rear] = x;
		}
	}
	else if(pri == 3){
		if(isFull(q3)){
		cout<<"cannot add "<<x<<" que3 is Full"<<endl;
		}
		else{
			q3->rear++; 
			q3->A[q3->rear] = x;
		}
	}
	else{
		cout<<"Error! unidentified priority!"<<endl;
	}
}
int que::deq(){
	int x = -1;
	if(!isEmpty(q1)){
		q1->front++;
		x = q1->A[q1->front];
	}
	else if(!isEmpty(q2)){
		q2->front++;
		x = q2->A[q2->front];
	}
	else if(!isEmpty(q3)){
		q3->front++;
		x = q3->A[q3->front];
	}
	else{
		cout<<"All Ques are empty!!  :  ";
	}
	return x;
}
void que::display(){
	cout<<"que1 : ";
	for(int i = q1->front +1; i<=q1->rear; i++){
		cout<<"  "<<q1->A[i]<<"  ";
	}
	cout<<endl;
	cout<<"que2 : ";
	for(int i =q2->front +1; i<=q2->rear; i++){
		cout<<" "<<q2->A[i]<<"  ";
	}
	cout<<endl;
	cout<<"que3 : ";
	for(int i =q3->front +1; i<=q3->rear; i++){
		cout<<q3->A[i]<<"  ";
	}
	cout<<endl;
	cout<<"--------------------"<<endl;
}
int que::isEmpty(qp* q){
	if(q->front == q->rear)
	 return 1;
	else 
	 return 0;
}
int que::isFull(qp* q){
	if(q->rear == size -1)
	 return 1;
	else 
	 return 0;
}

int main()
{
	que qu(4);
	qu.enq(1,1);
	qu.enq(1,3);
	qu.enq(2,5);
	qu.enq(3,9);
	qu.enq(2,15);
	qu.enq(3,54);
	qu.enq(3,41);
	qu.enq(3,19);
	qu.enq(1,200);
	qu.enq(1,202);
	qu.enq(1,500);
	qu.display();

	// qu.enq(6);
	// qu.display();

	qu.deq();
	qu.deq();
	qu.deq();
	qu.deq();
				
	qu.display();
	qu.deq();qu.deq();qu.deq();qu.deq();
	// qu.enq(6);
	qu.display();

	
return 0;
}