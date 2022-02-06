#include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;

class stak{
private: 
	
	int size = 50;
	int top =-1;
	char *s;
	
public:
	stak(){size = 0;};
	stak(string);
	~stak(){delete []s;}
	int getTop(){
		if(top<0) return -1;
		else return s[top];}

	void push(char);
	char pop();
	void Display();
	int peek(int);
	int isEmpty();
	int isFull();
	
};

stak::stak(string str){
	
	this->s = new char [25];

}

void stak::push(char x){
	
	if(top == size-1)
		cout<<"Stak overflow"<<endl;
	else{
		top++;
		s[top] = x;
	}
}
char stak::pop(){
	int x = -1;
	if(top==-1){
		cout<<"stak underflow"<<endl;
	}
	else{
		x = s[top];
		top--;
	}
	return x;
}
void stak::Display(){
	for (int i = top; i >= 0; i--)
	{
		cout<<s[i]<<endl;
	}
}
int stak::peek(int pos){
	// top+1 - pos = index
	if((top + 1 - pos)<0){
		cout<<"INVALID POSITION !!!"<<endl;
		return -1;
	}
	else
		return s[top+1 - pos]; 
}
int stak::isEmpty(){
	int x = getTop() == -1?  1 :  0;
	return x;
}
int stak::isFull(){
	int x = getTop() == size - 1 ?  1 :  0;
	return x;
}

int isOperand(char c){
	if(c=='+'|| c=='-'|| c=='*'|| c=='/'|| c=='^'|| c=='('|| c==')'){
		return 0;
	}
	else return 1;
}
int inpre(char x){
	if(x=='+'||x=='-')
		return 2;
	else if(x=='*'||x=='/')
		return 4;
	else if(x=='^')
		return 5;
	else if(x=='(')
		return 0;
	else
		return -1;
}
int outpre(char x){
	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 3;
	else if(x=='^')
		return 6;
	else if(x=='(')
		return 7;
	else if(x==')')
		return 0;
	else return -1;
}
char* infixTOPostfix(string str){
	stak st(str);
	char * pf = new char[str.length()];
	int j = 0; int i =0;
	while( i<str.length()){
		if(isOperand(str[i])){
			pf[j++] = str[i++];
		}
		else{
			if(inpre(str[i]) > inpre(st.getTop())){
				st.push(str[i++]);
			}
			else{
				pf[j++] = st.pop();
			}
		}
	}
	while(!st.isEmpty()){
	pf[j++] = st.pop();
	}
	return pf;
}
string infixTOPostfix1(string str){
	stak st(str);

	//char * pf = new char[str.length()];
	string pf = "";

	 int i =0;
	while( i < str.length() ){
		if(isOperand(str[i])){
			pf= pf + str[i++];
		}
		else{
			if(outpre(str[i]) > inpre(st.getTop()) ){
				st.push(str[i++]);
			}
			else if (outpre(str[i])==inpre(st.getTop())){
				int y = st.pop();
			}
			else{
				pf = pf + st.pop();
			}
		}
	}
	while(!st.isEmpty() && st.getTop() != ')'){
	pf= pf + st.pop();
	}
	return pf;
}
int eval(string A){
	
	stak ev(A);

	for(int i =0; i<A.length(); i++){
		if(isOperand(A[i]))
			ev.push(A[i] - '0');
		else{
			int x = ev.pop();
			int y = ev.pop();
			int val;
			switch(A[i]){
				case '+': 
					val = y+x;
					ev.push(val);
				break;

				case '-': 
					val = y-x;
					ev.push(val);
				break;

				case '*': 
					val = y*x;
					ev.push(val);
				break;

				case '/': 
					val = y/x;
					ev.push(val);
				break;

				case '^': 
					val = pow(y,x);
					ev.push(val);
				break;
			}
		}
	}
	int ans  = ev.pop();
	return ans;
}

int main()
{
	string str;
	// cout<<"Enter expression : ";
	// cin>>str;
	str ="((2+4)*3-6+3^3^2)";
	
	//string A = infixTOPostfix(str); // only 4 operator + - / *
	string A = infixTOPostfix1(str); // only 7 operator + - / * ^ ( )

	for (int i = 0; i <A.length(); i++)
	{
		cout<<A[i];
	}
	// different function
	cout<<endl;
	string A = "234*+82/-";
	cout<<eval(A)<<endl;


return 0;
}