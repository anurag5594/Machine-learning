#include<iostream>
using namespace std;

int firstoccurence (int arr[], int size, int key){

	int ans = -1;
	int s = 0;
	int e = size - 1;
	

	while(s <= e){
		int mid = s + (e - s)/2;

		if(key == arr[mid]){
			ans = mid ;
			e = mid - 1 ;
		}

		else if (arr[mid] < key)
  		{
  			s = mid + 1;
  		}

  		else //arr[mid] > key
  		{
            e = mid - 1;
  		}

  		
	}

	return ans;
}


int lastoccurence (int arr[], int size, int key){

	int ans = -1;
	int s = 0;
	int e = size - 1;
	int mid = s + (e - s)/2;

	while(s <= e){

		if(key == arr[mid]){
			ans = mid;
			s = mid + 1 ;
		}

		else if (arr[mid] < key)
  		{
  			s = mid + 1;
  		}

  		else if (arr[mid] > key)
  		{
            e = mid - 1;
  		}

  		mid = s + (e - s)/2; 
	}

	return ans;
}

int main(){

	int num[9] = {4,6,2,2,2,2,8,10,12};

	
	 cout<<"First occurence of 2 is"<<firstoccurence(num,9,2)<<endl;

	 cout<<"last occurence of 2 is"<<lastoccurence(num,9,2)<<endl;


}
