#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

char * swaping (char s[], int n, int m ){
	char temp = s[n];
		s[n] = s[m];
		s[m] = temp;
		return s;
}

void fun(char s[],int l , int h){
	int i =0;
	if(l==h){
		cout<<s<<endl;
	}
	else{
		for (i=l; s[i]!='\0'; i++)
		{
			swaping(s,i,l);
			fun(s,l+1,h);
			swaping(s,l,i);
		}
	}
}

int main()
{
	system("CLS");

	char s[] = "ABC";
	cout<<"Enter number of characters then characters with spaces"<<endl;
	int n ;
	cin>> n ;
	for (int i = 0; i < n; i++)
	{
		cin>> s[i] ;
	}
	cout<< "-------"<<endl;
	fun(s,0,n-1);

return 0;
}
