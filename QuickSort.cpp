#include <iostream>
#include <vector>

using namespace std;

void getUserInput(int* &arr, int &size) {
	cout << "Size of array to sort: ";
	cin >> size;
	
	arr = new int[size];
	cout << "Enter " << size << " elements:" << endl;

	for(int i = 0; i < size; i++) {
		cin >> arr[i];	
  }
}

void swap(int &a, int &b) {
	int c;
	c = a;
	a = b;
	b = c;
}

void quicksort(int arr[], int left, int right) {
	int pivot = (left + right)/2;
	int i = left, j = right;

	while(i <= j) {
		//find first element LHS that's > pivot
		while(arr[i] < arr[pivot])
			i++;
		//find first element RHS that's < pivot
		while(arr[j] > arr[pivot])
			j--;
		//swap elements at indices i & j, increment both		
		if(i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
  }

	if(left < j)
		quicksort(arr,left,j);

	if(right > i)
		quicksort(arr,i,right);
}

void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(int argv, char** argc) {
	int* arr;
	int size;
	
	getUserInput(arr,size);
	quicksort(arr,0,size-1);
	printArray(arr,size);
}
