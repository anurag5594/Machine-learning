#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{

	for(int i = 1; i<n; i++){

		for(j = 0; j < n-i; j++){

			if(arr[j]<arr[j+1]){
				swap(arr[j],arr[j+1])
			}
		}
	}
}

int main(){

	int s[5]={5,6,7,2,1};

	int n=5;

	cout<<"sorted element are :- "<<bubblesort(int s[5],5 ) ;
}