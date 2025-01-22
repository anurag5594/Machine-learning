 #include<iostream>
using namespace std;
int binarysearch(int arr[], int size, int key){

	int start = 0;
	int end = size-1;

	int mid = (start + end)/2;

  	while(start <= end){

  		if(arr[mid] == key){
  			return mid;
  		}

  		else if (arr[mid] < key)
  		{
  			start = mid + 1;
  		}

  		else //arr[mid] > key
  		{
            end = mid - 1;
  		}

  		mid = (start + end)/2;


  	}

  	return -1;
}

int main()

{
	int even[6] = {2,4,6,8,10,12};
	int odd[5] = {1,3,5,7,9};

	int evenindex = binarysearch(even,6,10);
	cout<<"Index of 10 is "<<evenindex<<endl;

	int oddindex = binarysearch(odd,5,1);
	cout<<"Index of 1 is "<<oddindex<<endl;
	return 0;
}
