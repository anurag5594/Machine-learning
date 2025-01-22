#include<iostream>
using namespace std;
 int getpivot(int arr[],int size){

 	int s = 0;
 	int e = size-1;

 	int mid = s + (e-s)/2;

 	while(s<e){

 		if(arr[mid]>=arr[0]){
 			
 			s = mid + 1;

 		}

 		else{
 			
 			e = mid;

 		}
 		int mid = s + (e-s)/2;
 	}
 	return s;
 }

 int main(){

 	int arr[5]={1,2,3,4,5};

 	cout<< "The piovet element"<< getpivot(arr,5) << endl;
 }