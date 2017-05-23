#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void quicksort(int* a, int low, int high) {
	if(low >= high)
		return;

	int pivot = a[(low+high)/2];
	int i = low, j = high;

	// while left indexer <= right indexer
	while(i <= j) {
		// find first int from left that isn't < pivot
		while(a[i] < pivot) i++;
		// find first int from right that isn't > pivot
		while(a[j] > pivot) j--;

		// swap the two, increment
		if(i <= j) {
			swap(a[i],a[j]);
			i++; j--;
		}
	}

	// recurse both halves
	quicksort(a,low,j);
	quicksort(a,i,high);
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
