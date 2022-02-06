#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class term{
public:
	int cof;
	int exp;
};

class Poly{
private:
	int n;
	term *t;
public:
	Poly(int n){
		this->n = n;
		
	}
	~Poly(){
		delete []t;
	}
	void Create();
	void Display();
	int Evaluate(int);
	Poly operator+(Poly &p1);
	//Poly add(Poly ,Poly );
};
void Poly::Create(){
	t = new term[n];
	cout<<"Enter coeff and exp"<<endl;
	for(int i =0; i<n; i++)
		cin>>t[i].cof>>t[i].exp;
}
void Poly::Display(){
	cout<<"f(x) = ";
	for(int i =0; i<n; i++){
		cout<<t[i].cof<<"x"<<t[i].exp;
		if(i!=n-1)
		cout<<" + ";
	}
	cout<<endl;
}
int Poly::Evaluate(int val){
	
	int sum;
	for (int i = 0; i < n; i++)
		sum = sum + t[i].cof*pow(val,t[i].exp) ;
	
	return sum;
}
Poly Poly::operator+(Poly &p1){
//Poly Poly::add(Poly p, Poly p1){
	Poly *sum = new Poly(4+n); 
	
	int i =0; int j=0; int k=0;
	while(i<n && j< p1.n){
		if(t[i].exp>p1.t[j].exp)
			sum->t[k++]=t[i++];
		else if (t[i].exp<p1.t[j].exp)
			sum->t[k++]=p1.t[j++];
		else {
			sum->t[k].exp = t[i].exp; 
			sum->t[k++].cof = t[i++].cof + p1.t[j++].cof;
		}
	}
	for (; i < n; i++)
	{
		sum->t[k++] = t[i];
	}
	for (; j < p1.n; j++)
	{
		sum->t[k++] = p1.t[j];
	}
	sum->n = k;
	return *sum;
}
int main()
{
	int n;
	cout<< "Enter no. of terms"<<endl;
	cin>>n;
	Poly p(n);
	p.Create();
	p.Display();

	Poly p1(4);
	p1.Create();
	p1.Display();

	// Poly p2(8) ;
	// p2 = p.add(p,p1);
	// p2.Display();
	Poly p2 = p + p1;

	cout<<"Press 1 if you wish to evaluate the polynomial for x"<<endl;
	int choice;
	cin>>choice;
	if(choice==1){
		int val;
		cout<<"Enter value of x"<<endl;
		cin>>val;
		cout<<"x = "<<val<<endl;
		cout<<"Value of above polynomial for x = "<<val<<" is "<<p2.Evaluate(val);
	}
return 0;
}