#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Binary_using_loop(int Arr[], int n, int key){

	int s = 0;
	int e = n;
	while(s<=e){
		int  mid = (s+e)/2;
		
		if(Arr[mid]==key)
			return mid;
		else if(Arr[mid]>key)
			e = mid-1;
		else
			s=mid+1;
	}
	return -1;

}
int RecursiveBinary(int Arr[], int low ,int high, int key){

	if(low<=high){
		int  mid = (low + high)/2;
		
		if(Arr[mid]==key)
			return mid;
		else if(key<Arr[mid])
			return RecursiveBinary(Arr, low, mid-1, key);
		else
			return RecursiveBinary(Arr, mid+1, high, key);
	}
	return -1;
}

int main()
{
	int arr[15] = {2, 4, 7, 9, 16, 17, 18, 19, 26, 27, 30, 35, 38, 39, 40};
	int num;
	cout<<"enter a no. between 0 to 40"<<endl;
	cin>>num;
	cout<<"using loop"<<endl<< Binary_using_loop(arr,15,num)<<endl;
	cout<<"using recursion"<<endl<<RecursiveBinary(arr,0,15,num);
	
return 0;
}