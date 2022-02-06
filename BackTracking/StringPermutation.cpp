#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void perm(char s[], int k){

	static  int A[5] = {0};
	static  char res[5] = {0};

	if(s[k]=='\0'){
		res[k] = '\0';
		cout<<res<<endl;
	}
	else{
		for(int i=0; s[i]!='\0'; i++){
			if(A[i]==0){
				res[k] = s[i];
				A[i] = 1;
				perm(s,k+1);
				A[i]=0;
			}
		}
	}
}

int main()
{	
	system("cls");
	char s[4] = {'A','B','C','\0'};
	perm(s,0);

return 0;
}