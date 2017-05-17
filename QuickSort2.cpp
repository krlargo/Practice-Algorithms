#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void quicksort(int* arr, int low, int high) {
	if(low >= high)
		return;

	int pivot = arr[(low+high)/2];
	int i = low, j = high;
	while(i <= j) {
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;

		if(i <= j) {
			swap(arr[i],arr[j]);
			i++; j--;
		}
	}

	quicksort(arr,low,j);
	quicksort(arr,i,high);
}

int main(int argv, char** argc) {
	int n;
	cout << "How many elements in array?" << endl;
	cin >> n;

	int arr[n];
	
	cout << "Enter " << n << " elements:" << endl;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	printArray(arr,n);

	quicksort(arr,0,n-1);
	printArray(arr,n);
}
