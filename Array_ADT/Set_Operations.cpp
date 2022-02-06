#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Union(int A[],int B[]){
	int* c = new int[13];
	int i  =0, j=0, k=0;
	while(i<6 && j<7){
		if(A[i]<B[j]){
			c[k] = A[i];
			i++;
		}
		else if (B[j]<A[i]){
			c[k] = B[j];
			j++;
		}
		else{
			c[k] = A[i];
			i++;
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

	for(int l =0; l<k; l++)
	{
		cout<<c[l]<<" ";
	}

}
void Intersection(int A[],int B[]){

	int* c = new int[6];
	int i=0, j=0, k=0;

	while(i<6 && j <7){
		if(A[i]<B[j]){
			i++;
		}
		else if (B[j]<A[i]){
			j++;
		}
		else{
			c[k] = A[i];
			i++;
			j++;
			k++;
		}
	}
	for(int l =0; l<k; l++)
	{
		cout<<c[l]<<" ";
	}
}
void Difference(int A[],int B[]){
	
	int* c = new int[6];
	int i=0, j=0, k=0;

	while(i<6 && j<7){
		if(A[i]<B[j]){
			c[k] = A[i];
			i++;
			k++;
		}
		else if (B[j]<A[i]){
			j++;
		}
		else{
			i++;
			j++;
		}
	}
	// for (int n = 0; n < 6; n++)
	// {	
	// 	bool flag = true;
	// 	for (int m = 0; m < 7; m++)
	// 	{
	// 		if(A[n]==B[m]){
	// 			flag=false;
	// 			break;
	// 		}
	// 	}
	// 	if(flag){
	// 	c[k] = A[n]; 
	// 	k++;
	// 	}
	// }
	
	for(int z = 0; z<k; z++)
		cout<< c[z]<<" ";
	
	
}

int main()
{
	system("cls");
	int* A = new int [6] {1,2, 3, 4, 5, 6};
	int* B = new int [7] {2, 4, 6, 8, 12, 14, 15};
	
	int n;
	cout<< "------Menu------"<<endl;
	cout<<"1 - Union" << endl << "2 - Intersection"<<endl<<"3 - Difference (A -B)"<<endl;
	cout<<"Choose a number. "<<endl;
	cin >> n;

	switch (n)
	{
	case 1: 
		Union(A,B);
		break;
	
	case 2:
		Intersection(A,B);
		break;
	
	case 3:
		Difference(A,B);
		break;
	
	default: cout <<"Invalid Input...Aborting now..."<<endl;
		break;
	}


return 0;
}