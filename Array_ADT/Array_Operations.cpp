#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Array {
	int *A;
	int size;
	int length;
};

void Display(struct Array arr){

	cout<<"Elements are"<<endl;

	for (int i = 0; i < arr.length; i++)
		cout<<arr.A[i]<< " ";
	cout<<endl;
}

void Add(struct Array arr,int n){
	if(arr.length<arr.size){
		arr.A[arr.length] = n;
		arr.length++;
	}
}

void Insert(struct Array arr,int num, int index){
	if(index>=0 && index<=arr.length){
		for (int i = arr.length-1; i>=index; i--){
			arr.A[i+1]=arr.A[i];
		}
		arr.A[index] = num;
		arr.length++;
	}
}

int Delete(struct Array arr, int index){
	int x =0;
	if(index>=0 && index<arr.length){
		x = arr.A[index];
		for (int i = index; i<arr.length-1; i++)
			arr.A[i]=arr.A[i+1];
		
		arr.length--;
		return x;
	}
	return 0;	
}

int search(struct Array arr,int num){
	for (int i = 0; i < arr.length; i++)
	{
		if(arr.A[i]==num)
			return i;
	}
	return -1;
}
int Get(struct Array arr,int index){
	if(index>=0 && index<arr.length)
		return arr.A[index];
	return -1;
}
void Set(struct Array arr,int num, int index){
	if(index>=0 && index<arr.length)
		arr.A[index] = num;
}
int Max(struct Array arr){
	int max = -1;
	for (int i = 0; i < arr.length; i++)
	{
		if(arr.A[i]>max)
			max = arr.A[i];
	}
	return max;
}
int Min(struct Array arr){
	int min = arr.A[0] ;
	for (int i = 0; i < arr.length; i++)
	{
		if(arr.A[i]<min)
			min = arr.A[i];
	}
	return min;
}
int Sum(struct Array arr){
	int sum = 0;
	for (int i = 0; i < arr.length; i++)
	{
		sum  = sum + arr.A[i];
	}
	return sum;
}
int Average(struct Array arr){
	int sum = 0;
	for (int i = 0; i < arr.length; i++)
	{
		sum  = sum + arr.A[i];
	}
	int average = sum / arr.length;
	return average;
}


int main()
{
	system("cls");
	struct Array arr;

	cout<<"Enter the size of array"<<endl;
	cin>> arr.size;

	arr.A = new int[arr.size];

	cout<<"Enter the length of array"<<endl;
	cin>> arr.length;

	cout<<"Enter the elements"<<endl;
	for (int i = 0; i < arr.length; i++)
	{
		cin>>arr.A[i];
	}

	Display(arr);

	int m;
	cout<<"Select a number according to operation from below"<<endl;
	cout<<"1 - Append"<<"\n"<<"2 - Insert"<<"\n"<<"3 - Delete"<<"\n"<<"4 - Search"<<endl;
	cout<<"5 - Get"<<"\n"<<"6 - Set"<<"\n"<<"7 - Max"<<"\n"<<"8 - Min"<<"\n"<<"9 - Sum"<<"\n"<<"10 - Average"<<endl;
	cout<<"Your input is : ";

	cin>>m;

	switch(m){
		case 1:
			int n ;
			cout<<"Enter number to append"<<endl;
			cin>>n;
			Add(arr,n);
			Display(arr);
		  break;

		case 2:
			int n1,n2;
			cout<<"Enter number to insert and index"<<endl;
			cin>>n1>>n2;
			Insert(arr,n1,n2);
			Display(arr);
		  break;

		case 3:
			int n3;
			cout<<"Enter index to delete"<<endl;
			cin>>n3;
			cout<<Delete(arr,n3)<<endl;;
			Display(arr);
		  break;

		case 4:
			int n4;
			cout<<"Enter number to search"<<endl;
			cin>>n4;
			cout<<"number is  at index - "<<search(arr,n4)<<endl;
			Display(arr);
		  break;

		case 5:
			int n5;
			cout<<"Enter index"<<endl;
			cin>>n5;
			Display(arr);
			cout<<"Element at index "<<n5<<"is"<<Get(arr,n5);
		  break;

		case 6:
			int n6,n7;
			cout<<"Enter number and Index"<<endl;
			cin>>n6>>n7;
			Set(arr,n6,n7);
			Display(arr);
		  break;

		case 7:
			Display(arr);
			cout<<"largest element is "<<Max(arr)<<endl;
		  break;

		case 8:
			Display(arr);
			cout<<"smallest element is "<<Min(arr)<<endl;
		  break;
		
		case 9:
			Display(arr);
			cout<<"sum of all elements is "<<Sum(arr)<<endl;
		  break;
		
		case 10:
			Display(arr);
			cout<<"Average of elements of array is "<< Average(arr)<<endl;
		  break;
		  
		default :
			Display(arr);
	}

return 0;
}