#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){

	for(int i = 0;i < n-1; i++){

		int minindex = i;

		for (int j = i+1; j<n; j++){

			if (arr[j]<arr[minindex])
				minindex=j;


		}

		swap(arr[minindex],arr[i]);

	}
}

int main(){

	int arr[6]={5,3,7,6,4,9};
	int n;
	cin>>n;

	selectionsort(arr[6],n);
}