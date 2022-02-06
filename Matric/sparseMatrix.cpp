#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Element {

public:
	int i;
	int j;
	int x;
};

class Sparse{
  private:
    int m;
	int n;
	int num;
	Element *e ;

  public:
	Sparse(int m, int n, int num){
		this->m = m;
		this->n = n;
		this->num= num;
		this->e = new Element[this->num];
	}
	~Sparse(){
		delete []e;
	}
	
	// void Read();
	// void Display();
	// int Sum();
	Sparse operator+(Sparse &s);
	friend istream & operator>>(istream &is,Sparse &s);
	friend ostream & operator<<(ostream &os,Sparse &s);

};

Sparse Sparse::operator+(Sparse &s)
{
	Sparse *sum = new Sparse(m, n, num + s.num);
	if(m!=s.m || n !=s.n){
		cout<<"check dimensions";
		exit;
	}
	
	int i =0 ; int j=0; int k=0;
	while (i<num && j<s.num){

		if(e[i].i < s.e[j].i)
			sum-> e [k++] = e[i++];
		
		else if(e[i].i > s.e[j].i)
			sum-> e [k++] = s.e[j++];
		
		else {
			if(e[i].j < s.e[j].j)
				sum-> e[k++] = e[i++];
			else if(e[i].j > s.e[j].j)
				sum-> e[k++] = s.e[j++];
			else {
			sum-> e[k] = e[i++];
			sum-> e[k++].x += s.e[j++].x;
			}
		}
	}
	for (; i < num; i++)
	{
		sum->e[k++] = e[i];
	}
	for (; j < s.num; j++)
	{
		sum->e[k++] = s.e[j];
	}
	sum->num = k;
	return *sum;
}


istream & operator>>(istream &is,Sparse &s){
	// cout<<"Enter Dimensions"<<endl;
	// cin>>m>>n;
	// cout<<"Enter no. of non-zero elements"<<endl;
	// cin>>num;
	// e = new Element[num];
	cout<<"Enter all non-zero elements"<<endl;
	for(int i =0; i<s.num; i++)
		cin>> s.e[i].i >> s.e[i].j>> s.e[i].x;
 	return is;
}

ostream & operator<<(ostream &os,Sparse &s){
	
	int z = 0;
	for(int i = 0; i<s.m; i++){
		for(int j =0; j<s.n; j++){
			if(i==s.e[z].i && j == s.e[z].j)
				cout<<s.e[z++].x<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
	return os;
}

// int Sparse::Sum(){
// 	Sparse *sum;
// 	if(s1.m!=s2.m || s1.n !=s2.n)
// 		return 0;
// 	sum = new Sparse;
// 	sum->m = s1.m;
// 	sum->n = s1.n;
// 	sum->e  = new Element(s1.num + s2.num);

// 	int i =0 ; int j=0; int k=0;
// 	while (i<s1->num && j<s2.num){

// 		if(s1->e[i].i < s2->e[j].i){
// 			sum-> e [k++] = s1->e[i++];
// 		}
// 		else if(s1->e[i].i > s2->e[j].i){
// 			sum-> e [k++] = s2->e[j++];
// 		}
// 		else {
// 			if(s1->e[i].j < s2->e[j].j)
// 				sum-> e[k++] = s1->e[i++];
// 			else if(s1->e[i].j > s2->e[j].j)
// 				sum-> e[k++] = s2->e[j++];
// 			else {
// 			sum -> e[k] = s1->e[i++];
// 			sum->e[k++].x+=s2->e[j++].x;
// 			}
// 		}
// 	}
// 	sum->num = k;
// }

int main()
{
	system("CLS"); 
	Sparse s(5,5,5);
	Sparse s2(5,5,5);
	cin>>s;
	cin>>s2;
	//s1.Read();
	//s1.Display();

	Sparse sum = s+s2;
	cout<<"First Matrix"<<endl<<s;
	cout<<"Second Matrix"<<endl<<s2;
	cout<<"Sum matrix"<<endl<<sum;

return 0;
}