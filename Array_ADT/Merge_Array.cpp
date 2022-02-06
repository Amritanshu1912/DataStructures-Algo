#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int* mergesort(int A[],int B[])
{
	int *c = new int [13];
	int i = 0, j =0, k=0;

	while(i<6 && j<7){
		if(A[i]<B[j]){
			c[k] = A[i];
			i++;
		}
		else {
			c[k] = B[j];
			j++;
		}
		k++;
	}
	for(;i<6;i++){
		c[k++] = A[i];
	}
	for(;j<7;j++){
		c[k++] = B[j];	
	}

return c;
}

void Display(int C[]){
	for (int i = 0; i < 13; i++)
	{
		cout<< C[i]<<" ";
	}
	cout<<endl;
	
}

int main()
{
	//your_code_here
	int A[6]={7,12,23,56,65,76};
	int B[7]={10,27,39,44,88,91,98};

	Display(mergesort(A,B));

return 0;
}